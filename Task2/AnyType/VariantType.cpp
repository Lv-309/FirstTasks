#include "VariantType.h"

ISXVariantType::VariantType::VariantType()
		: float_value(0)
		, stored_type(VariantBasicTypes::BasicTypeUndefined)
{ }

ISXVariantType::VariantType::VariantType(const VariantBasicTypes& enum_obj)
		: stored_type(enum_obj)
{ }

ISXVariantType::VariantType::VariantType(const VariantType& another)
		: VariantType(another.stored_type)
{ 
	switch (another.stored_type)
	{
	case VariantBasicTypes::BasicTypeUndefined:
		break;
	case VariantBasicTypes::BasicTypeBool:
		bool_value = another.bool_value;
		break;
	case VariantBasicTypes::BasicTypeChar:
		char_value = another.char_value;
		break;
	case VariantBasicTypes::BasicTypeInt:
		int_value = another.int_value;
		break;
	case VariantBasicTypes::BasicTypeFloat:
		float_value = another.float_value;
		break;
	default:
		break;
	}
}