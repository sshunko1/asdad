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
#include "fwddec.hpp"
#include "handle.hpp"

#include <cstdint>
#include <optional>
#include <string_view>
#include <vector>

namespace memory
{
	class pattern
	{
		friend pattern_batch;
		friend range;

	public:
		pattern(std::string_view ida_sig);

		inline pattern(const char* ida_sig) :
		    pattern(std::string_view(ida_sig))
		{
		}

		std::vector<std::optional<uint8_t>> m_bytes;
	};
}
