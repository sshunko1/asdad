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
#include "script_global.hpp"

namespace big
{
	script_global::script_global(std::size_t index) :
		m_index(index)
	{
	}

	script_global script_global::at(std::ptrdiff_t index)
	{
		return script_global(m_index + index);
	}

	script_global script_global::at(std::ptrdiff_t index, std::size_t size)
	{
		return script_global(m_index + 1 + (index * size));
	}

	void *script_global::get()
	{
		return g_pointers->m_gta.m_script_globals[m_index >> 0x12 & 0x3F] + (m_index & 0x3FFFF);
	}
}
