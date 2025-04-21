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

#include <vector>

namespace memory
{
	class range
	{
	public:
		range(handle base, std::size_t size);

		handle begin() const;
		handle end() const;
		std::size_t size() const;

		bool contains(handle h) const;

		std::optional<handle> scan(pattern const& sig) const;
		std::vector<handle> scan_all(pattern const& sig) const;

	protected:
		handle m_base;
		std::size_t m_size;
		DWORD m_timestamp;
	};
}
