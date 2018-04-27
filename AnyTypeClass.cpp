#include <iostream>
#include "AnyTypeClass.h"

AnyType::AnyType(bool in)
{
	U.b = in;
	type_of_value = 1;
}

AnyType::AnyType(char in)
{
	U.ch = in;
	type_of_value = 2;
}

AnyType::AnyType(int in)
{
	U.i = in;
	type_of_value = 3;
}

AnyType::AnyType(double in)
{
	U.d = in;
	type_of_value = 4;
}


AnyType AnyType::operator = (const AnyType& temp)
{
	switch (temp.type_of_value)
	{
	case 1:
		U.b = temp.U.b;
		break;
	case 2:
		U.ch = temp.U.ch;
		break;
	case 3:
		U.i = temp.U.i;
		break;
	case 4:
		U.d = temp.U.d;
		break;
	default:
		U.d = 0.0;
		break;
	}
	type_of_value = temp.type_of_value;
	return AnyType();
};

bool AnyType::ToBool() const
{
	if (type_of_value == 1)
		return U.b;
	else
		throw TypeError();
}

char AnyType::ToChar() const
{
	if (type_of_value == 2)
		return U.ch;
	else
		throw TypeError();
}

int AnyType::ToInt() const
{
	if (type_of_value == 3)
		return U.i;
	else
		throw TypeError();
}

double AnyType::ToDouble() const
{
	if (type_of_value == 4)
		return U.d;
	else
		throw TypeError();
}

void AnyType::ReturnType() const
{
	switch (type_of_value)
	{
	case 1:
		std::cout << " Type of value is - bool" << std::endl;
		break;
	case 2:
		std::cout << " Type of value is - char" << std::endl;
		break;
	case 3:
		std::cout << " Type of value is - integer" << std::endl;
		break;
	case 4:
		std::cout << " Type of value is - double" << std::endl;
		break;
	default:
		std::cout << " Type of value is - Error" << std::endl;
		break;
	}
}
