#include "AnyType.h"
#include "Exceptions.h"

AnyType& AnyType::ToBool()
{
	switch (flag)
	{
	case BOOL_TYPE:
		return *this;
	case CHAR_TYPE:
		if (var.char_var == NULL)
			var.bool_var = false;
		else var.bool_var = true;
		flag = BOOL_TYPE;
		return *this;
	case INT_TYPE:
		if (var.int_var == 0)
			var.bool_var = false;
		else var.bool_var = true;
		flag = BOOL_TYPE;
		return *this;
	case DOUBLE_TYPE:
		if (var.double_var == 0)
			var.bool_var = false;
		else var.bool_var = true;
		flag = BOOL_TYPE;
		return *this;
	default:
		try
		{
			throw (NoFundamentalTypeAssigned());
		}
		catch (NoFundamentalTypeAssigned& msg)
		{
			cout << msg.what();
			cout << " before converting to bool." << endl;
		}
	}
}

AnyType& AnyType::ToChar()
{
	char tmp;
	switch (flag)
	{
	case BOOL_TYPE:
		if (var.bool_var == false)
			var.char_var = '\0';
		//else EXCEPTION;
		flag = CHAR_TYPE;
		return *this;
	case CHAR_TYPE:
		return *this;
	case INT_TYPE:
		tmp = (char)var.int_var;
		var.char_var = tmp;
		flag = CHAR_TYPE;
		return *this;
	case DOUBLE_TYPE:
		tmp = (char)var.double_var;
		var.char_var = tmp;
		flag = CHAR_TYPE;
		return *this;
	default:
		try
		{
			throw (NoFundamentalTypeAssigned());
		}
		catch (NoFundamentalTypeAssigned& msg)
		{
			cout << msg.what();
			cout << " before converting to char." << endl;
		}
	}
}

AnyType& AnyType::ToInt()
{
	int tmp;
	switch (flag)
	{
	case BOOL_TYPE:
		if (var.bool_var == true)
			var.int_var = 1;
		else var.int_var = 0;
		flag = INT_TYPE;
		return *this;
	case CHAR_TYPE:
		tmp = (int)var.char_var;
		var.int_var = tmp;
		flag = INT_TYPE;
		return *this;
	case INT_TYPE:
		return *this;
	case DOUBLE_TYPE:
		tmp = (int)var.double_var;
		var.int_var = tmp;
		flag = INT_TYPE;
		return *this;
	default:
		try
		{
			throw (NoFundamentalTypeAssigned());
		}
		catch (NoFundamentalTypeAssigned& msg)
		{
			cout << msg.what();
			cout << " before converting to int." << endl;
		}
	}
}

AnyType& AnyType::ToDouble()
{
	double tmp;
	switch (flag)
	{
	case BOOL_TYPE:
		if (var.bool_var == true)
			var.double_var = 1;
		else var.double_var = 0;
		flag = DOUBLE_TYPE;
		return *this;
	case CHAR_TYPE:
		tmp = (double)var.char_var;
		var.double_var = tmp;
		flag = DOUBLE_TYPE;
		return *this;
	case INT_TYPE:
		tmp = var.int_var;
		var.double_var = tmp;
		return *this;
	case DOUBLE_TYPE:
		return *this;
	default:
		try
		{
			throw (NoFundamentalTypeAssigned());
		}
		catch (NoFundamentalTypeAssigned& msg)
		{
			cout << msg.what();
			cout << " before converting to double." << endl;
		}
	}
}

void AnyType::Print()
{
	switch (flag)
	{
	case BOOL_TYPE:
		cout << var.bool_var << endl;
		break;
	case CHAR_TYPE:
		cout << var.char_var << endl;
		break;
	case INT_TYPE:
		cout << var.int_var << endl;
		break;
	case DOUBLE_TYPE:
		cout << var.double_var << endl;
		break;
	default:
		try
		{
			throw (NoFundamentalTypeAssigned());
		}
		catch (NoFundamentalTypeAssigned& msg)
		{
			cout << msg.what();
			cout << " before printing." << endl;
		}
	}
}

const char* AnyType::GetType()
{
	switch (flag)
	{
	case BOOL_TYPE:
		return ("bool");
	case CHAR_TYPE:
		return ("char");
	case INT_TYPE:
		return ("int");
	case DOUBLE_TYPE:
		return ("double");
	default:
		return ("A fundamental type was not assigned to this variable.");
	}
}

ostream& operator << (ostream &os, const AnyType &a)
{
	switch (a.flag)
	{
	case BOOL_TYPE:
		os << a.GetBool();
		return os;
	case CHAR_TYPE:
		os << a.GetChar();
		return os;
	case INT_TYPE:
		os << a.GetInt();
		return os;
	case DOUBLE_TYPE:
		os << a.GetDouble();
		return os;
	default:
		try
		{
			throw (NoFundamentalTypeAssigned());
		}
		catch (NoFundamentalTypeAssigned& msg)
		{
			cout << msg.what();
			cout << " before printing." << endl;
		}
	}
}

void Swap(AnyType &a, AnyType &b)
{
	AnyType tmp = a;
	a = b;
	b = tmp;
}
