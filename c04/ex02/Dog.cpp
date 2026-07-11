#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#include <iostream>
#include <string>

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor is called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor is called" << std::endl;
	brain = new Brain(*(other.brain));
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator is called" << std::endl;
	if (this == &other)
		return (*this);
	delete brain;
	Animal::operator=(other);
	brain = new Brain(*(other.brain));
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor is called" << std::endl;
	delete brain;
}

void	Dog::makeSound() const
{
	std::cout << "woof woof!" << std::endl;
}
