#include <iostream>
#include <string>

#include "AnyTypeClass.h"

using namespace std;

int main()
{
	AnyType anyType, second;

	try{
		anyType = 65;
		int i = anyType.ToInt();
		cout << i << endl;
		anyType.ReturnType();
	
		anyType = 79.5;
		double d = anyType.ToDouble();
		cout << d << endl;
		anyType.ReturnType();

		anyType = 'a';
		char ch = anyType.ToChar();
		cout << ch << endl;
		anyType.ReturnType();
		
		anyType = true;
		bool b = anyType.ToBool();
		cout << b << endl;
		anyType.ReturnType();

		//bool test = anyType.ToDouble();

		anyType = 98;
		second = anyType;

		i = second.ToInt();
		cout << i << endl;
	}
	catch (AnyType::TypeError)
	{
		cout << "WARNING! Different types of variables!";
	}

	cout << endl << "Hello! From end of programm" << endl;

	system("pause");
	return 0;
}
