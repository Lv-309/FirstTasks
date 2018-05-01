#include <iostream>
#include <exception>
#include "AnyType.h"

using namespace std;
using namespace ISXAnyType;

int main()
{
	AnyType test1 = 5;
	AnyType test2 = 'Q';
	AnyType test3(test2);
	AnyType test4;
	
	test1 = test4 = test2;
	
	test3 = 5.5f;

	try
	{
		float d_var = test3.ToFloat();
		char  c_var = test2.ToChar();
		cout << test1.GetType() << endl;
	}
	catch (const char* ex)
	{
		cerr << ex << endl;
	}
}