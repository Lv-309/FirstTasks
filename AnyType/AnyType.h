#pragma once
#include <iostream>
#include <algorithm>
#include <typeinfo>

enum TypeNameEnum { Int, Float, Double, Char, Bool, Unspecified };

union DataTypes
{
	int int_type;
	float float_type;
	double double_type;
	char char_type;
	bool bool_type;
};

class AnyType
{
	TypeNameEnum type_name_enum = Unspecified;
	DataTypes data_types = { 0 };

public:
	AnyType()
	{
		data_types.double_type = 0;
		type_name_enum = Unspecified;
	}

	AnyType(const AnyType& other_obj)
	{
		data_types = other_obj.data_types;
		type_name_enum = other_obj.type_name_enum;
	}

	template<typename T>
	AnyType(const T& _any_type)
	{
		std::string type_name = DetermineType(_any_type);

		if (type_name == "Int")
		{
			data_types.int_type = _any_type;
			type_name_enum = Int;
		}
		else if (type_name == "Float")
		{
			data_types.float_type = _any_type;
			type_name_enum = Float;
		}
		else if (type_name == "Double")
		{
			data_types.double_type = _any_type;
			type_name_enum = Double;
		}
		else if (type_name == "Char")
		{
			data_types.char_type = _any_type;
			type_name_enum = Char;
		}
		else if (type_name == "Bool")
		{
			data_types.bool_type = _any_type;
			type_name_enum = Bool;
		}
	}

	~AnyType() {}

	template<typename T>
	void operator= (const T& _any_type)
	{
		std::string type_name = DetermineType(_any_type);

		if (type_name == "Int")
		{
			data_types.int_type = _any_type;
			type_name_enum = Int;
		}
		else if (type_name == "Float")
		{
			data_types.float_type = _any_type;
			type_name_enum = Float;
		}
		else if (type_name == "Double")
		{
			data_types.double_type = _any_type;
			type_name_enum = Double;
		}
		else if (type_name == "Char")
		{
			data_types.char_type = _any_type;
			type_name_enum = Char;
		}
		else if (type_name == "Bool")
		{
			data_types.bool_type = _any_type;
			type_name_enum = Bool;
		}
	}

	void operator= (const AnyType& other_obj)
	{
		data_types = other_obj.data_types;
		type_name_enum = other_obj.type_name_enum;
	}

	int ToInt() const
	{
		if (type_name_enum != Int) throw "Wrong type";

		return data_types.int_type;
	}
	float ToFloat() const
	{
		if (type_name_enum != Float) throw "Wrong type";

		return data_types.float_type;
	}
	double ToDouble() const
	{
		if (type_name_enum != Double) throw "Wrong type";

		return data_types.double_type;
	}
	char ToChar() const
	{
		if (type_name_enum != Char) throw "Wrong type";

		return data_types.char_type;
	}
	bool ToBool() const
	{
		if (type_name_enum != Bool) throw "Wrong type";

		return data_types.bool_type;
	}

	template <typename U, typename O>
	static auto Swap(U& first_element, O& second_element)
	{
		return std::swap(first_element, second_element);
	}

	template <typename T>
	static std::string DetermineType(const T& _any_type)
	{
		std::string type_name;

		if (typeid(_any_type).name() == typeid(int).name())
		{
			type_name = "Int";
		}
		else if (typeid(_any_type).name() == typeid(float).name())
		{
			type_name = "Float";
		}
		else if (typeid(_any_type).name() == typeid(double).name())
		{
			type_name = "Double";
		}
		else if (typeid(_any_type).name() == typeid(char).name())
		{
			type_name = "Char";
		}
		else if (typeid(_any_type).name() == typeid(bool).name())
		{
			type_name = "Bool";
		}

		return type_name;
	}
};
