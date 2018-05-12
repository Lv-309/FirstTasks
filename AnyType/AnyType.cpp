#include "AnyType.h"
using namespace ISXAnyType;


int AnyType::ToInt() const
{
	if (this->value.type_id != Int)
		throw AnyTypeException();
	return value.data.var_int;
}
char AnyType::ToChar() const
{
	if (this->value.type_id != Char)
		throw AnyTypeException();
	return value.data.var_char;
}
double AnyType::ToDouble() const
{
	if (this->value.type_id != Double)
		throw AnyTypeException();
	return value.data.var_double;
}
bool AnyType::ToBool() const
{
	if (this->value.type_id != Bool)
		throw AnyTypeException();
	return value.data.var_bool;
}
const std::wstring  AnyType::GetType() const
{
	switch (this->value.type_id)
	{
	case Char: return L"char"; break;
	case Int: return L"int"; break;
	case Double: return L"double"; break;
	case Bool: return L"bool"; break;
	default: return L"undefined"; break;
	}
}
void AnyType::Swap(AnyType& obj)
{
	AnyType temp(obj);
	obj.value = this->value;
	this->value = temp.value;
	return;
}
std::ostream& ISXAnyType::operator <<(std::ostream& os, const AnyType& var)
{
	switch (var.value.type_id)
	{
	case Char: os << var.value.data.var_char; break;
	case Int: os << var.value.data.var_int; break;
	case Double: os << var.value.data.var_double; break;
	case Bool: os << var.value.data.var_bool; break;
	case Undef: os << "Type is undefined"; break;
	}
	return os;
}