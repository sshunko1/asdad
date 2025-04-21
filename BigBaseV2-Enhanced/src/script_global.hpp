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
	class script_global
	{
	public:
		explicit script_global(std::size_t index);

		script_global at(std::ptrdiff_t index);
		script_global at(std::ptrdiff_t index, std::size_t size);

		template <typename T>
		std::enable_if_t<std::is_pointer_v<T>, T> as()
		{
			return static_cast<T>(get());
		}

		template <typename T>
		std::enable_if_t<std::is_lvalue_reference_v<T>, T> as()
		{
			return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(get());
		}
	private:
		void *get();
		std::size_t m_index;
	};
}
