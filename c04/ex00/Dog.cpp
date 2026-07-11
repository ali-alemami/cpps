#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog()
{
	std::cout << "Dog default constructor is called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor is called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator is called" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "woof woof!" << std::endl;
}
