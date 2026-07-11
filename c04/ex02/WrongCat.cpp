#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor is called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor is called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator is called" << std::endl;
	if (this == &other)
		return (*this);
	WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor is called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "wrong meow" << std::endl;
}
