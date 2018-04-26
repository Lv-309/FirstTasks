#pragma once

namespace ISXVariantType
{
	enum VariantBasicTypes
	{
		BasicTypeUndefined, BasicTypeBool, BasicTypeChar, BasicTypeInt, BasicTypeFloat
	};

	struct VariantType
	{
		VariantType();
		VariantType(const VariantType&			another);
		VariantType(const VariantBasicTypes&	enum_obj);

		union 
		{
			int		int_value;
			char	char_value;
			bool	bool_value;
			float	float_value;
		};
		VariantBasicTypes stored_type;
	};
}
