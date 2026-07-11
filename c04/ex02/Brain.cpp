#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor is called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor is called" << std::endl;
	for (int i = 0; i <= 99; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}
Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator is called" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i <= 99; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called" << std::endl;
}
