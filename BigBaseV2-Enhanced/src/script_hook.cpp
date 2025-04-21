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
#include "script_hook.hpp"

namespace big
{
	script_hook::~script_hook()
	{
		if (m_vmt_hook)
		{
			m_vmt_hook->disable();
		}
	}

	void script_hook::ensure()
	{
		if (m_vmt_hook)
			return;
	}
}
