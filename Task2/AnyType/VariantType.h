#pragma once

namespace ISXVariantType
{
// Maybe better create another namespace especial for enum
enum VariantBasicTypes
{
	BasicTypeUndefined, BasicTypeBool, BasicTypeChar, BasicTypeInt, BasicTypeFloat
};
// Struct wrapper for union
struct VariantType
{
	// Ctors for casting
	VariantType();
	VariantType(const VariantType&		another);
	VariantType(const VariantBasicTypes&	enum_obj);
	// Global(for struct) anonymous union
	union 
	{
		int	int_value;
		char	char_value;
		bool	bool_value;
		float	float_value;
	};
	// Variables
	VariantBasicTypes stored_type;
};
	
}
