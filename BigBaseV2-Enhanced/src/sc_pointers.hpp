#pragma once
#include "function_types.hpp"

namespace big
{
	// needed for serialization of the pointers cache
#pragma pack(push, 1)
	struct socialclub_pointers
	{
		PVOID m_read_attribute_patch3;
	};
#pragma pack(pop)

	static_assert(sizeof(socialclub_pointers) % 8 == 0, "Pointers are not properly aligned");
}
