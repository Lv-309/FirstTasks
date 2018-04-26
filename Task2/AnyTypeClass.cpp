#include "stdafx.h"
#include "AnyTypeClass.h"

AnyType& AnyType::operator=(AnyType other)
{
	switch (other.CurrentType)
	{
	case INT:
	{
		SomeType.int_type = other.get_int_type();
		CurrentType = INT;
		return *this;
	}
	case CHAR:
	{
		SomeType.char_type = other.get_char_type();
		CurrentType = CHAR;
		return *this;
	}
	case BOOL:
	{
		SomeType.bool_type = other.get_bool_type();
		CurrentType = BOOL;
		return *this;
	}
	case DOUBLE:
	{
		SomeType.double_type = other.get_double_type();
		CurrentType = DOUBLE;
		return *this;
	}
	default:
		std::cout << "Incorrect type to swap" << std::endl;
		return *this;
	}
}

std::string AnyType::ReturnType() const
{
	switch (CurrentType)
	{
	case INT:
		return "Current type is integer";
	case BOOL:
		return "Current type is bool";
	case CHAR:
		return "Current type is char";
	case DOUBLE:
		return "Current type is double";
	default:
		return "Current type is undefined";
	}
}

void AnyType::swap(AnyType& other)
{
	AnyType temp = other;
	other = *this;
	*this = temp;
}

int AnyType::get_int_type() const
{
	try
	{
		if (CurrentType == INT)
			return SomeType.int_type;
		else throw exceptionType();
	}
	catch (exceptionType& e)
	{
		std::cout << e.what();
		return 0;
	}
}
bool AnyType::get_bool_type() const
{
	try
	{
		if (CurrentType == BOOL)
			return SomeType.bool_type;
		else throw exceptionType();
	}
	catch (exceptionType& e)
	{
		std::cout << e.what();
		return false;
	}
}
char AnyType::get_char_type() const
{
	try
	{
		if (CurrentType == CHAR)
			return SomeType.char_type;
		else throw exceptionType();
	}
	catch (exceptionType& e)
	{
		std::cout << e.what();
		return '\0';
	}
}
double AnyType::get_double_type() const
{
	try
	{
		if (CurrentType == DOUBLE)
			return SomeType.double_type;
		else throw exceptionType();
	}
	catch (exceptionType& e)
	{
		std::cout << e.what();
		return 0.0;
	}
}