#include "AnyType.h"

int main()
{
	AnyType any_type = 1;

	try
	{
		int stored_value_int = any_type.ToInt();
		std::cout << "Int: " << stored_value_int << "\n\n";
	}
	catch (...)
	{
		std::cout << "Exception!\n\n";
	}

	any_type = false;

	try
	{
		bool stored_value_bool = any_type.ToBool();
		std::cout << "Bool: " << stored_value_bool << "\n\n";
	}
	catch (...)
	{
		std::cout << "Exception!\n\n";
	}

	any_type = (float)1.7;

	try
	{
		float stored_value_float = any_type.ToFloat();
		std::cout << "Float: " << stored_value_float << "\n\n";
	}
	catch (...)
	{
		std::cout << "Exception!\n\n";
	}

	any_type = 2.89;

	try
	{
		double stored_value_double = any_type.ToDouble();
		std::cout << "Double: " << stored_value_double << "\n\n";
	}
	catch (...)
	{
		std::cout << "Exception!\n\n";
	}

	any_type = 'c';
	char stored_value_char = any_type.ToChar();
	std::cout << "Char: " << stored_value_char << "\n\n";

	// Swapping
	AnyType first = 4;
	AnyType second = 5;
	second = true;

	try
	{
		auto stored_first_before = first.ToInt();
		auto stored_second_before = second.ToBool();

		std::cout << "Before swap:\n" << "first: " << stored_first_before << "\n" << "second: " << stored_second_before << "\n\n";
	}
	catch (...)
	{
		std::cout << "Exception before swapping!\n\n";
	}

	AnyType::Swap(first, second);

	try
	{
		auto stored_first_after = first.ToBool();
		auto stored_second_after = second.ToInt();

		std::cout << "After swap:\n" << "first: " << stored_first_after << "\n" << "second: " << stored_second_after << "\n\n";
	}
	catch (...)
	{
		std::cout << "Exception after swapping!\n\n";
	}
	// End swapping

	try
	{
		AnyType some_char_value = 'k';
		char stored_some_char_value = some_char_value.ToChar();
		std::cout << "Stored some char: " << stored_some_char_value << "\n\n";
	}
	catch (...)
	{
		std::cout << "Exception!\n\n";
	}

	AnyType first_obj = 9;
	AnyType second_obj(first_obj); // copy constr
	AnyType third_obj = first_obj; // copy constr
	third_obj = second_obj; // copy assignment opertr

	try
	{
		std::cout << "First obj: " << first_obj.ToInt() << "\n";
		std::cout << "Second obj: " << second_obj.ToInt() << "\n";
		std::cout << "Third obj: " << third_obj.ToInt() << "\n\n";
	}
	catch (...)
	{
		std::cout << "Exception!\n\n";
	}

	system("pause");
	return 0;
}