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

namespace big
{
	class file_manager;

	class file
	{
	public:
		file(const std::filesystem::path& file_path = "");
		void operator=(const file& other);
		operator std::filesystem::path();
		operator std::filesystem::path&();

		file copy(const std::filesystem::path& new_path);
		bool exists() const;
		const std::filesystem::path get_path() const;
		file move(std::filesystem::path new_path);

	private:
		friend class file_manager;

		bool m_is_project_file;
		std::filesystem::path m_file_path;
	};
}