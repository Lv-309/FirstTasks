#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <exception>

class AnyType
{
public:
	AnyType() { std::cout << "Object is not initialized!" << std::endl; }
	AnyType(int int_value) { SomeType.int_type = int_value; CurrentType = INT; }
	AnyType(bool bool_value) { SomeType.bool_type = bool_value; CurrentType = BOOL; }
	AnyType(char char_value) { SomeType.char_type = char_value; CurrentType = CHAR; }
	AnyType(double double_value) { SomeType.double_type = double_value; CurrentType = DOUBLE; }

	~AnyType() {}

	std::string ReturnType() const;
	void swap(AnyType&);

	AnyType& operator=(int int_value) { SomeType.int_type = int_value; CurrentType = INT; return *this; }
	AnyType& operator=(bool bool_value) { SomeType.bool_type = bool_value; CurrentType = BOOL; return *this; }
	AnyType& operator=(char char_value) { SomeType.char_type = char_value; CurrentType = CHAR; return *this; }
	AnyType& operator=(double double_value) { SomeType.double_type = double_value; CurrentType = DOUBLE; return *this; }
	AnyType& operator=(AnyType);

	int get_int_type() const;
	bool get_bool_type() const;
	char get_char_type() const;
	double get_double_type() const;
private:
	union
	{
		int int_type;
		bool bool_type;
		char char_type;
		double double_type = 0.0;
	} SomeType;
	enum
	{
		BOOL, CHAR, INT, DOUBLE
	} CurrentType;
};

class exceptionType : public std::exception
{
public:
	const char* what() const throw()
	{
		return "Incorrect type and value : ";
	}
};