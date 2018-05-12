#pragma once
#include <iostream>
#include "AnyTypeException.h"

namespace ISXAnyType
{

struct NewType {
	friend class AnyType;
	int type_id;
	union Data {
		char var_char;
		int var_int;
		double var_double;
		bool var_bool;
	}data;
};

enum TypeOfValue
{
	Char,
	Int,
	Double,
	Bool,
	Undef
};

class AnyType
{
private:
	NewType value;
public:
	AnyType()
	{
		value.type_id = Undef;
	}
	AnyType(char character)
	{
		value.type_id = Char;
		value.data.var_char = character;
	}
	AnyType(int number)
	{
		value.type_id = Int;
		value.data.var_int = number;
	}
	AnyType(double real)
	{
		value.type_id = Double;
		value.data.var_double = real;
	}
	AnyType(bool a)
	{
		value.type_id = Bool;
		value.data.var_bool = a;
	}
	AnyType(const AnyType& some)
	{
		this->value = some.value;
	}

	int ToInt() const;
	char ToChar() const;
	double ToDouble() const;
	bool ToBool() const;

	template <class T>
	AnyType& operator =(const T& obj)
	{
		AnyType temp(obj);
		this->value = temp.value;

		return *this;
	}
	const std::wstring GetType() const;
	void Swap(AnyType&);

	friend std::ostream& operator <<(std::ostream&, const AnyType&);

};


}	// namespace ISXAnyType
