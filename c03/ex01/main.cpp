#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

int	main()
{
	ScavTrap	scavTrap1("ali");
	ScavTrap	scavTrap2("omar");
	ScavTrap	scavTrap4(scavTrap1);

	scavTrap2 = scavTrap1;

	std::cout << "ScavTrap name: " << scavTrap1.getName() << std::endl;
	std::cout << "ScavTrap hitpoints: " << scavTrap1.getHitPoints() << std::endl;
	std::cout << "ScavTrap energyPoints: " << scavTrap1.getEnergyPoints() << std::endl;
	std::cout << "ScavTrap attackDamage: " << scavTrap1.getAttackDamage() << std::endl;

	scavTrap1.attack("omar");
	std::cout << "ScavTrap _energyPoints: " << scavTrap1.getEnergyPoints() << std::endl;

	scavTrap1.takeDamage(5);
	std::cout << "ScavTrap hitpoints: " << scavTrap1.getHitPoints() << std::endl;
	

	scavTrap1.takeDamage(10);
	std::cout << "ScavTrap hitpoints: " << scavTrap1.getHitPoints() << std::endl;

	scavTrap1.beRepaired(10);
	std::cout << "ScavTrap hitpoints: " << scavTrap1.getHitPoints() << std::endl;
	std::cout << "ScavTrap _energyPoints: " << scavTrap1.getEnergyPoints() << std::endl;

	scavTrap1.guardGate();
	
	return (0);
}
