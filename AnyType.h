#pragma once

#include <string>

class AnyType
{
private:
	union{
		bool b;
		char ch;
		int i;
		double d = 0.0;
	} U;

	int type_of_value = 0;

public:
	AnyType(){};
	AnyType(bool in);
	AnyType(char in);
	AnyType(int in);
	AnyType(double in);

	class TypeError
	{
	};

	
	AnyType operator = (const AnyType& );

	bool ToBool()const;
	char ToChar()const;
	int ToInt()const;
	double ToDouble()const;
	void ReturnType()const;
};
