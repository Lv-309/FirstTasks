#include "stdafx.h"
#include "AnyTypeClass.h"


int main()
{
	AnyType one = 7;

	std::cout << one.get_int_type() << std::endl;
	std::cout << one.get_double_type() << std::endl;
	std::cout << one.ReturnType() << std::endl;

	AnyType second = 'c';

	std::cout << second.get_char_type() << std::endl;
	std::cout << second.get_int_type() << std::endl;
	std::cout << second.ReturnType() << std::endl;

	one.swap(second);

	std::cout << second.get_int_type() << std::endl;
	std::cout << one.get_char_type() << std::endl;

	system("pause");
	return 0;
}