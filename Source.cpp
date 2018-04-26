#include <iostream>

#include "AnyType.h"

int main() 
{
	int a1 = 10;
	double d1 = 0.67;
	char ch1 = 'c';

	AnyType val1 = a1;
	
	int a2 = 0;	

	try 
	{
		a2 = val1.ToInt();
		std::cout << a2 << std::endl;
	}

	catch (const Exeption& e) {
		std::cerr << " EXCEPTION: [ " << e.what() << " ] " << std::endl
			      << " IN FUCTION: [ " << e.where() << " ] " << std::endl;
	}

	val1 = d1;
    double d2 = 0;

	try 
	{
		d2 = val1.ToDouble();
		std::cout << d2 << std::endl;
	}
	catch (const Exeption& e) {
		std::cerr << " EXCEPTION: [ " << e.what() << " ] " << std::endl
			<< " IN FUCTION: [ " << e.where() << " ] " << std::endl;
	}

	val1 = ch1;
	int ch2 = 34;

	try
	{
		ch2 = val1.ToChar();
		std::cout << ch2 << std::endl;
	}
	catch (const Exeption& e) {
		std::cerr << " EXCEPTION: [ " << e.what() << " ] " << std::endl
			<< " IN FUCTION: [ " << e.where() << " ] " << std::endl;
	}

	AnyType type1 = 12.3;
	AnyType type2 = 'f';

	type1.Swap(type2);

	double stype1;
	char stype2;

	try 
	{
		stype1 = type2.ToChar();
		stype2 = type1.ToChar();
		
		std::cout << stype1 << std::endl;
		std::cout << stype2 << std::endl;

	}
	catch (const Exeption& e) {
		std::cerr << " EXCEPTION: [ " << e.what() << " ] " << std::endl
			<< " IN FUCTION: [ " << e.where() << " ] " << std::endl;
	}
	
	std::cout << "Enter any key to continue...";
	std::cin.get();
}