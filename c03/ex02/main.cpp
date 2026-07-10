#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>
#include "FragTrap.hpp"

int	main()
{
	FragTrap	fragTrap1("ali");
	FragTrap	fragTrap2("omar");
	FragTrap	fragTrap4(fragTrap1);

	fragTrap2 = fragTrap1;

	std::cout << "FragTrap name: " << fragTrap1.getName() << std::endl;
	std::cout << "FragTrap hitpoints: " << fragTrap1.getHitPoints() << std::endl;
	std::cout << "FragTrap energyPoints: " << fragTrap1.getEnergyPoints() << std::endl;
	std::cout << "FragTrap attackDamage: " << fragTrap1.getAttackDamage() << std::endl;

	fragTrap1.attack("omar");
	std::cout << "FragTrap _energyPoints: " << fragTrap1.getEnergyPoints() << std::endl;

	fragTrap1.takeDamage(5);
	std::cout << "FragTrap hitpoints: " << fragTrap1.getHitPoints() << std::endl;
	

	fragTrap1.takeDamage(10);
	std::cout << "FragTrap hitpoints: " << fragTrap1.getHitPoints() << std::endl;

	fragTrap1.beRepaired(10);
	std::cout << "FragTrap hitpoints: " << fragTrap1.getHitPoints() << std::endl;
	std::cout << "FragTrap _energyPoints: " << fragTrap1.getEnergyPoints() << std::endl;

	fragTrap1.highFivesGuys();
	
	return (0);
}
