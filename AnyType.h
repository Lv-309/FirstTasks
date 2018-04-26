#pragma once

#include <iostream>

using namespace std;

union FundamentalTypes
{
	friend class AnyType;

private:
	bool bool_var;
	char char_var;
	int int_var;
	double double_var = 0; // initialize the biggest variable
};

enum Type {
	BOOL_TYPE, CHAR_TYPE, INT_TYPE, DOUBLE_TYPE, NOT_A_FUNDAMENTAL_TYPE
};

class AnyType
{
private:
	FundamentalTypes var;
	Type flag;

public:
	AnyType()
	{
		var.double_var = NULL;
		flag = Type::NOT_A_FUNDAMENTAL_TYPE;
	}

	AnyType(bool a)
	{
		var.bool_var = a;
		flag = Type::BOOL_TYPE;
	}

	AnyType(char a)
	{
		var.char_var = a;
		flag = Type::CHAR_TYPE;
	}

	AnyType(int a)
	{
		var.int_var = a;
		flag = Type::INT_TYPE;
	}

	AnyType(double a)
	{
		var.double_var = a;
		flag = Type::DOUBLE_TYPE;
	}

	AnyType(const AnyType &a) : var(a.var), flag(a.flag) {}

	~AnyType() {}

	AnyType& operator=(const AnyType &a)
	{
		var = a.var;
		flag = a.flag;
		return *this;
	}

	AnyType& operator=(const bool a)
	{
		var.bool_var = a;
		flag = BOOL_TYPE;
		return *this;
	}

	AnyType& operator=(const char a)
	{
		var.char_var = a;
		flag = CHAR_TYPE;
		return *this;
	}

	AnyType& operator=(const int a)
	{
		var.int_var = a;
		flag = INT_TYPE;
		return *this;
	}

	AnyType& operator=(const double a)
	{
		var.double_var = a;
		flag = DOUBLE_TYPE;
		return *this;
	}

	friend ostream& operator << (ostream &os, const AnyType &a);

	//friend istream& operator >> (istream& is, AnyType &a);

	AnyType &ToBool();

	AnyType &ToChar();

	AnyType &ToInt();

	AnyType &ToDouble();

	bool GetBool() const
	{
		if (flag == BOOL_TYPE)
			return var.bool_var;
		else
		{
			AnyType copy = *this;
			copy.ToBool();
			return copy.var.bool_var;
		}
	}

	char GetChar() const
	{
		if (flag == CHAR_TYPE)
			return var.char_var;
		else
		{
			AnyType copy = *this;
			copy.ToChar();
			return copy.var.char_var;
		}
	}

	int GetInt() const
	{
		if (flag == INT_TYPE)
			return var.int_var;
		else
		{
			AnyType copy = *this;
			copy.ToInt();
			return copy.var.int_var;
		}
	}

	double GetDouble() const
	{
		if (flag == DOUBLE_TYPE)
			return var.double_var;
		else
		{
			AnyType copy = *this;
			copy.ToDouble();
			return copy.var.double_var;
		}
	}



	void Print();

	const char* GetType(); // wstring???wcout doesn't work

	friend void Swap(AnyType &a, AnyType &b);


};


