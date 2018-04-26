#pragma once

#include <iostream>
#include <exception>

using namespace std;

class NoFundamentalTypeAssigned : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Assign a fundamental type to the variable";
	}
};

