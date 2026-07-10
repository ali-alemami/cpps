#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	diamondTrap1("ali");
	DiamondTrap	diamondTrap2("omar");
	DiamondTrap	diamondTrap4(diamondTrap1);

	diamondTrap2 = diamondTrap1;

	std::cout << "DiamondTrap name: " << diamondTrap1.getName() << std::endl;
	std::cout << "DiamondTrap hitpoints: " << diamondTrap1.getHitPoints() << std::endl;
	std::cout << "DiamondTrap energyPoints: " << diamondTrap1.getEnergyPoints() << std::endl;
	std::cout << "DiamondTrap attackDamage: " << diamondTrap1.getAttackDamage() << std::endl;

	diamondTrap1.attack("omar");
	std::cout << "FragTrap _energyPoints: " << diamondTrap1.getEnergyPoints() << std::endl;

	diamondTrap1.takeDamage(5);
	std::cout << "FragTrap hitpoints: " << diamondTrap1.getHitPoints() << std::endl;
	

	diamondTrap1.takeDamage(10);
	std::cout << "FragTrap hitpoints: " << diamondTrap1.getHitPoints() << std::endl;

	diamondTrap1.beRepaired(10);
	std::cout << "FragTrap hitpoints: " << diamondTrap1.getHitPoints() << std::endl;
	std::cout << "FragTrap _energyPoints: " << diamondTrap1.getEnergyPoints() << std::endl;

	diamondTrap1.attack("omar");
	diamondTrap1.whoAmI();
	
	return (0);
}
