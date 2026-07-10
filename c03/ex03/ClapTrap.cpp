#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "ClapTrap Constructor is called" << std::endl;

	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy constructor is called" << std::endl;

	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy assignment operator is called" << std::endl;

	if (this == &other)
		return (*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor is called" << std::endl;
	// nothing to free here :)
}

std::string ClapTrap::getName(void) const
{
	return (_name);
}

void ClapTrap::setName(const std::string& name)
{
	_name = name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	_hitPoints = hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	_energyPoints = energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	_attackDamage = attackDamage;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack right now!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
	<< _attackDamage << " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hitPoints)
	{
		std::cout << "ClapTrap " << _name <<
		" has taken [" << amount << "] of damage and died!" << std::endl;
		_hitPoints = 0;
		return ;
	}
	std::cout << "ClapTrap " << _name <<
	" has taken [" << amount << "] of damage!" << std::endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't repair himself!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name <<
	" repaired himself with [" << amount << "] of health!" << std::endl;
	_hitPoints += amount;
	_energyPoints -= 1;
}
