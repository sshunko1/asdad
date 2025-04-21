/*
 * �������� / Disclaimer
 *
 * ����Ŀ�� Codeant ��Դ������ѧϰ���о�ʹ�ã�**��ֹ�κ���ʽ����ҵ��;**��
 * ʹ�ñ���������ɵ��κκ����ʹ���߳е���Codeant ���е��κ����Ρ�
 *
 * This project is open-sourced by Codeant and is intended for **non-commercial use only**.
 * The author shall not be held responsible for any consequences caused by the use of this code.
 *
 * �� Codeant
 */
#pragma once
#include "common.hpp"
#include "script.hpp"

namespace big
{
    void Script::ScriptExceptionHandler(PEXCEPTION_POINTERS exp)
    {
        HMODULE mod{};
        DWORD64 offset{};
        char buffer[MAX_PATH]{};
        if (GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)exp->ExceptionRecord->ExceptionAddress, &mod) == TRUE && mod != nullptr)
        {
            offset = ((DWORD64)exp->ExceptionRecord->ExceptionAddress - (DWORD64)mod);
            GetModuleFileNameA(mod, buffer, MAX_PATH - 1);
        }
       // LOG(FATAL) << "Exception Code: " << HEX_TO_UPPER(exp->ExceptionRecord->ExceptionCode) << " Exception Offset: " << HEX_TO_UPPER(offset) << " Fault Module Name: " << buffer;
    }

    Script::Script(std::function<void()> scriptAction) {
        action = scriptAction;
        m_main_fiber = nullptr;

        m_script_fiber = CreateFiber(0, [](void* param) {
            Script* thisScript = (Script*)(param);
            thisScript->fiber_func();
            }, this);
    }

    Script* Script::get_current() {
        return (Script*)(GetFiberData());
    }

    void Script::yield(std::optional<std::chrono::high_resolution_clock::duration> time) {
        if (time.has_value())
            wake = std::chrono::high_resolution_clock::now() + time.value();
        else
            wake = std::nullopt;

        SwitchToFiber(m_main_fiber);
    }

    void Script::fiber_func() {
        std::invoke(action);

        while (true) {
            yield();
        }
    }

    void Script::tick() {
        m_main_fiber = GetCurrentFiber();
        if (!wake.has_value() || wake.value() <= std::chrono::high_resolution_clock::now())
            SwitchToFiber(m_script_fiber);
    }
}