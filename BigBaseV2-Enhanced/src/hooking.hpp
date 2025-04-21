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
#include "detour_hook.hpp"
#include "gta/fwddec.hpp"
#include "vmt_hook.hpp"

#include <Psapi.h>

namespace big
{
	struct hooks
	{
		static bool run_script_threads(__int64 a1, __int64** a2, unsigned __int64* a3, __int64 a4);
	};

	struct minhook_keepalive
	{
		minhook_keepalive();
		~minhook_keepalive();
	};

	class hooking
	{
		friend hooks;
	public:
		explicit hooking();
		~hooking();

		void enable();
		void disable();
	private:
		bool m_enabled{};
		minhook_keepalive m_minhook_keepalive;
		std::unique_ptr<vmt_hook> m_main_persistent_hook;
	};

	inline hooking *g_hooking{};
}
