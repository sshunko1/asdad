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

namespace big
{
	class featuress
	{
	public:
		static bool CheckForMultipleVersionDLL();
		static void anticheat_fsl_init();

		static void script_init();
		static void script_on_tick();
		static void script_func();
	};

	inline featuress g_features;
}
