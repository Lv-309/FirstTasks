#pragma once
#include "Eception.h"

class AnyType 
{
private:

	enum {UNDEFINED = -1,BOOL,INT,FLOAT,DOUBLE,LONGLONG,CHAR} variant;

	union {
		bool b;
		int i;
		float f;
		double d;
		long long l;
		char ch;
	};	

public:

	AnyType() 
	{
		variant = AnyType::UNDEFINED;
	}

	AnyType(bool val)
	{
		AnyType::b = val;
		variant = AnyType::BOOL;
	}

	AnyType(char val)
	{
		AnyType::ch = val;
		variant = AnyType::CHAR;
	}

	AnyType(int val)
	{
		AnyType::i = val;
		variant = AnyType::INT;
	}

	AnyType(double val)
	{
		AnyType::d = val;
		variant = AnyType::DOUBLE;
	}

	AnyType(float val)
	{
		AnyType::f = val;
		variant = AnyType::FLOAT;
	}

	AnyType(long long val)
	{
		AnyType::l = val;
		variant = AnyType::LONGLONG;
	}

	AnyType(const AnyType& val) 
	{
		this->variant = val.variant;

		switch (val.variant)
		{
		case AnyType::BOOL: this->b = val.b; break;
		case AnyType::CHAR: this->ch = val.ch; break;
		case AnyType::DOUBLE: this->d = val.d; break;
		case AnyType::FLOAT: this->f = val.f; break;
		case AnyType::INT: this->i = val.i; break;
		case AnyType::LONGLONG: this->l = val.l; break;
		default: break;
		}
	}

	AnyType& operator=(const AnyType& val) 
	{
		if (this != &val)
		{			
			this->variant = val.variant;

			switch (val.variant) 
			{
			case AnyType::BOOL     : this->b = val.b; break;
			case AnyType::CHAR     : this->ch = val.ch; break;
			case AnyType::DOUBLE   : this->d = val.d; break;
			case AnyType::FLOAT    : this->f = val.f; break;
			case AnyType::INT      : this->i = val.i; break;
			case AnyType::LONGLONG : this->l = val.l; break;
			default : break;
			}
		}

		return *this;
	}

	template<class T>
	AnyType& operator=(T val)
	{
			if (typeid(T) == typeid(bool)) 
			{
				this->variant = AnyType::BOOL;
				this->b = val;
				return *this;
			}

			else if (typeid(T) == typeid(char))
			{
				this->variant = AnyType::CHAR;
				this->ch = val;
				return *this;
			}

			else if (typeid(T) == typeid(double))
			{
				this->variant = AnyType::DOUBLE;
				this->d = val;
				return *this;
			}

			else if (typeid(T) == typeid(float))
			{
				this->variant = AnyType::FLOAT;
				this->f = val;
				return *this;
			}

			else if (typeid(T) == typeid(int))
			{
				this->variant = AnyType::INT;
				this->i = val;
				return *this;
			}
			
			else if (typeid(T) == typeid(long long))
			{
				this->variant = AnyType::LONGLONG;
				this->l = val;
				return *this;
			}		

		return *this;
	}

	bool ToBool() const 
	{
		if(variant == UNDEFINED)
			throw Exeption("Uninitialized","ToBool");

		if (variant != BOOL)
			throw Exeption("Variant doesn't contain bool data", "ToBool");

		return AnyType::b;
	}

	int ToInt() const 
	{
		if (variant == UNDEFINED)
			throw Exeption("Uninitialized", "ToInt");

		if (variant != INT)
			throw Exeption("Variant doesn't contain int data", "ToInt");

		return AnyType::i;
	}

	float ToFloat() const 
	{
		if (variant == UNDEFINED)
			throw Exeption("Uninitialized","ToFloat");

		if (variant != FLOAT)
			throw Exeption("Variant doesn't contain float data", "ToFloat");

		return AnyType::f;
	}

	double ToDouble() const 
	{
		if (variant == UNDEFINED)
			throw Exeption("Uninitialized","ToDouble");

		if (variant != DOUBLE) 
			throw Exeption("Variant doesn't contain double data", "ToDouble");

		return AnyType::d;
	}

	long long ToLongLong() const 
	{
		if (variant == UNDEFINED)
			throw Exeption("Uninitialized","ToLongLong");

		if (variant != LONGLONG)
			throw Exeption("Variant doesn't contain long long data","ToLongLong");

		return AnyType::l;
	}

	char ToChar() const 
	{
		if (variant == UNDEFINED)
			throw Exeption("Uninitialized","ToChar");

		if (variant != CHAR)
			throw Exeption("Variant doesn't contain char data","ToChar");

		return AnyType::ch;
	}

	void Swap(AnyType& val)
	{
		AnyType temp(val);
		val.variant = this->variant;

		switch (this->variant)
		{
		case AnyType::BOOL: val.b = this->b; break;
		case AnyType::CHAR: val.ch = this->ch; break;
		case AnyType::DOUBLE: val.d = this->d; break;
		case AnyType::FLOAT: val.f = this->f; break;
		case AnyType::INT: val.i = this->i; break;
		case AnyType::LONGLONG: val.l = this->l; break;
		default: break;
		}

		this->variant = temp.variant;

		switch (temp.variant)
		{
		case AnyType::BOOL: this->b = temp.b; break;
		case AnyType::CHAR: this->ch = temp.ch; break;
		case AnyType::DOUBLE: this->d = temp.d; break;
		case AnyType::FLOAT:this->f = temp.f; break;
		case AnyType::INT: this->i = temp.i; break;
		case AnyType::LONGLONG: this->l = temp.l; break;
		default: break;
		}
	}
};
