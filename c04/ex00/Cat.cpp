#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat()
{
	std::cout << "Cat default constructor is called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor is called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator is called" << std::endl;
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "meow meow ˃ ᴗ ˂" << std::endl;
}
