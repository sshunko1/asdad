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
#include "memory/module.hpp"

namespace big
{
	inline bool is_proton()
	{
		static auto module = memory::module("ntdll.dll");

		const auto env_no_color = std::getenv("NO_COLOR");
		return module.get_export("wine_get_version") || (env_no_color && strlen(env_no_color));
	}
}
