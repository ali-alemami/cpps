#include "Weapon.hpp"
#include <string>

Weapon::Weapon(const std::string& type)
{
	_type = type;
}

const std::string&	Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
