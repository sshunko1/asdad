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
	class script_mgr
	{
	public:
		explicit script_mgr() = default;
		~script_mgr() = default;

		void add_script(std::unique_ptr<Script> script);
		void remove_all_scripts();

		void tick();
	private:
		void tick_internal();
	private:
		std::recursive_mutex m_mutex;
		std::vector<std::unique_ptr<Script>> m_scripts;
	};

	inline script_mgr g_script_mgr;
}
