#pragma once
#include <exception>

struct AnyTypeException : public std::exception {
	const char* what() const throw () {
		return "Incorrect use of AnyType variable";
	}
};