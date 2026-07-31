#include "Data.hpp"

#include <cstddef>

Data::Data()
	: _value(0), _next(NULL)
{}

Data::Data(int value)
	: _value(value), _next(NULL)
{}

Data::Data(const Data& other)
	: _value(other._value), _next(NULL)
{
	if (other._next)
		_next = new Data(*other._next);
}

Data&	Data::operator=(const Data& other)
{
	if (this != &other)
	{
		_value = other._value;
		delete (_next);
		_next = NULL;
		if (other._next)
			_next = new Data(*other._next);
	}
	return (*this);
}

Data::~Data()
{
	delete (_next);
}
