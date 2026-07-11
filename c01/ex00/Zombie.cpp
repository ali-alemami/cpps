#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie()
{
	this->_name = "";
}

Zombie::Zombie(const Zombie& other)
{
	this->_name = other._name;
}

Zombie::Zombie(const std::string& name)
{
	this->_name = name;
}

Zombie& Zombie::operator=(const Zombie& other)
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	return (*this);
}

Zombie::~Zombie()
{
	std::cout << _name << " destroyed" << std::endl;
}

void	Zombie::setName(const std::string& name)
{
	this->_name = name;
}

std::string	Zombie::getName() const
{
	return (this->_name);
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
