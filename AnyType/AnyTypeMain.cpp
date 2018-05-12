#include "AnyType.h"

using namespace ISXAnyType;
using namespace std;


int main()
{
	AnyType var = 69.4;
	
	AnyType var2 = 123;
	double a = 2.3;
	int i_var = 6;
	try {
		a = var.ToBool();
	}
	catch (AnyTypeException& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		i_var = var.ToInt();
	}
	catch (AnyTypeException& e)
	{
		cout << e.what() << endl;
	}
	cout << a << endl;

	a = 46.2;
	var = a = 12.3;
	var = var2;

	cout << var << endl;
	system("pause");
	return 0;
}