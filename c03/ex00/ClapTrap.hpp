#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		std::string		getName(void) const;
		void			setName(const std::string& name);

		unsigned int	getHitPoints(void) const;
		void			setHitPoints(unsigned int hitPoints);

		unsigned int	getEnergyPoints(void) const;
		void			setEnergyPoints(unsigned int energyPoints);

		unsigned int	getAttackDamage(void) const;
		void			setAttackDamage(unsigned int attackDamage);

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif