#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap Constructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructor is called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap Copy assignment operator is called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor is called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " can't attack right now!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
	<< _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap requests a positive high-five!" << std::endl;
}
