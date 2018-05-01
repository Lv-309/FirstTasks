#pragma once
#include <string>
#include "VariantType.h"

namespace ISXAnyType
{

#define UNDEF	ISXVariantType::VariantBasicTypes::BasicTypeUndefined
#define BOOL	ISXVariantType::VariantBasicTypes::BasicTypeBool
#define CHAR	ISXVariantType::VariantBasicTypes::BasicTypeChar
#define INT	ISXVariantType::VariantBasicTypes::BasicTypeInt
#define FLOAT	ISXVariantType::VariantBasicTypes::BasicTypeFloat

class AnyType
{
public:
	// Public aliases
	typedef		std::string				string;
	typedef		ISXVariantType::VariantType		VariantStruct;
	// Ctors
	AnyType() = default;
	AnyType(const int&	i_value);
	AnyType(const bool&	b_value);
	AnyType(const char&	c_value);
	AnyType(const float&	f_value);
	AnyType(const AnyType&	another);
	~AnyType();
	// AnyType manipulators
	void   Destroy();
	string GetType() const;
	// AnyType casts
	int    ToInt()   const;
	bool   ToBool()  const;
	char   ToChar()  const;
	float  ToFloat() const;
	// Operator overloading
	AnyType& operator=(const AnyType& right);
private:
	VariantStruct m_variant;
};

void SwapAnyTypes(AnyType& left, AnyType& right);
	
}
