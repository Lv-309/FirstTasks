#pragma once
#include <exception>
#include <string.h>

class Exeption : public std::exception 
{
private:
	char* str_what;
	char* str_where;

public:
	Exeption() : str_what(nullptr), str_where(nullptr)
	{}
	explicit Exeption(const char* str_what, const char* str_where)
	{
		size_t length1 = strlen(str_what);
		this->str_what = new char[length1 + 1];
		strcpy(this->str_what, str_what);

		size_t length2 = strlen(str_where);
		this->str_where = new char[length2 + 1];
		strcpy(this->str_where, str_where);

	}
	~Exeption() 
	{
		delete[] str_what;
		delete[] str_where;
	}
	const char* what() const throw()
	{
		return str_what;
	}
	const char* where() const throw()
	{
		return str_where;
	}
};

