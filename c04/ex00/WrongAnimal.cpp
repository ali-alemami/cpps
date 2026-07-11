#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal()
{
	type = "";
	std::cout << "WrongAnimal default constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	type = other.type;
	std::cout << "WrongAnimal copy constructor is called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy assignment operator is called" << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor is called" << std::endl;
}

void	WrongAnimal::setType(const std::string& name)
{
	type = name;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Some generic wrongAnimal sound" << std::endl;
}
