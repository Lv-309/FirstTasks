#include "AnyType.h"
/*
 *  All Ctor's delegating type control to our VariantType
 *  struct's Ctor's.
 */

ISXAnyType::AnyType::AnyType(const int& i_value) 
		: m_variant(INT)
{
	m_variant.int_value = i_value;
}

ISXAnyType::AnyType::AnyType(const bool& b_value)	
		: m_variant(BOOL)
{
	m_variant.bool_value = b_value;
}

ISXAnyType::AnyType::AnyType(const char& c_value) 
		: m_variant(CHAR)
{
	m_variant.char_value = c_value;
}

ISXAnyType::AnyType::AnyType(const float& f_value) 
		: m_variant(FLOAT)
{
	m_variant.float_value = f_value;
}

ISXAnyType::AnyType::AnyType(const AnyType& another) 
		: m_variant(another.m_variant)
{ }

ISXAnyType::AnyType::~AnyType()
{ }

void ISXAnyType::AnyType::Destroy()
{
	m_variant.float_value = 0;
	m_variant.stored_type = UNDEF;
}

ISXAnyType::AnyType::string ISXAnyType::AnyType::GetType() const
{
	switch (m_variant.stored_type)
	{
	case UNDEF:	return "Undefined";
	case BOOL :	return "Bool";
	case CHAR :	return "Char";
	case INT  :	return "Int";
	case FLOAT:	return "Float";
	default   :	return "Error";
	}
}

int ISXAnyType::AnyType::ToInt() const
{
	if (m_variant.stored_type != INT)
		throw "Wrong assignment to integer";
	return m_variant.int_value;
}

bool ISXAnyType::AnyType::ToBool() const
{
	if (m_variant.stored_type != BOOL)
		throw "Wrong assignment to boolean";
	return m_variant.bool_value;
}

char ISXAnyType::AnyType::ToChar() const
{
	if (m_variant.stored_type != CHAR)
		throw "Wrong assignment to char";
	return m_variant.char_value;
}

float ISXAnyType::AnyType::ToFloat() const
{
	if (m_variant.stored_type != FLOAT)
		throw "Wrong assignment to float";
	return m_variant.float_value;
}

ISXAnyType::AnyType& ISXAnyType::AnyType::operator=(const AnyType& right)
{
	if (this != &right)
	{
		m_variant 		=  right.m_variant;
		m_variant.stored_type 	=  right.m_variant.stored_type;
	}
	return *this;
}

void ISXAnyType::SwapAnyTypes(AnyType& left, AnyType& right)
{
	AnyType temp	=  left;
	left		=  right;
	right		=  temp;
}
