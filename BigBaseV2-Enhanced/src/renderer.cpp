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
#include "renderer.hpp"
#include "pointers.hpp"

#include "hooks/d3d12hook.hpp"
#include "hooks/hooks.hpp"
#include "hooks/kiero.hpp"

namespace big
{
	renderer::renderer()
	{
		H::Init();

		g_renderer = this;
	}

	renderer::~renderer()
	{
		H::Free();

		g_renderer = nullptr;
	}
}