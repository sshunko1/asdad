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
#include "pointers.hpp"
#include "script_mgr.hpp"
#include "invoker.hpp"

namespace big
{
	void script_mgr::add_script(std::unique_ptr<Script> script)
	{
		std::lock_guard lock(m_mutex);
		m_scripts.push_back(std::move(script));
	}

	void script_mgr::remove_all_scripts()
	{
		std::lock_guard lock(m_mutex);
		m_scripts.clear();
	}

	void script_mgr::tick()
	{
		tick_internal();
	}

	void script_mgr::tick_internal()
	{
		static bool ensure_main_fiber = (ConvertThreadToFiber(nullptr), true);
		if (!ensure_main_fiber)
			return;

		static bool ensure_native_handlers = (g_native_invoker.cache_handlers(), true);
		if (!ensure_native_handlers)
			return;

		std::lock_guard lock(m_mutex);
		for (auto const& script : m_scripts)
		{
			script->tick();
		}
	}
}