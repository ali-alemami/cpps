#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#include <iostream>
#include <string>

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor is called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor is called" << std::endl;
	brain = new Brain(*(other.brain));
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator is called" << std::endl;
	if (this == &other)
		return (*this);
	delete brain;
	Animal::operator=(other);
	brain = new Brain(*(other.brain));
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor is called" << std::endl;
	delete brain;
}

void	Cat::makeSound() const
{
	std::cout << "meow meow ˃ ᴗ ˂" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return (brain);
}
