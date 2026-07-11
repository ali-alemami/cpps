#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal()
{
	type = "";
	std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	type = other.type;
	std::cout << "Animal copy constructor is called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment operator is called" << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor is called" << std::endl;
}

void	Animal::setType(const std::string& name)
{
	type = name;
}

std::string	Animal::getType() const
{
	return (type);
}
