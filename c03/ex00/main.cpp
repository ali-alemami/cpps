#include "ClapTrap.hpp"
#include <string>
#include <iostream>

int	main()
{
	ClapTrap	clapTrap1("ali");
	ClapTrap	clapTrap2("omar");
	ClapTrap	clapTrap4(clapTrap1);

	clapTrap2 = clapTrap1;

	std::cout << "ClapTrap1 name: " << clapTrap1.getName() << std::endl;
	std::cout << "ClapTrap1 hitpoints: " << clapTrap1.getHitPoints() << std::endl;
	std::cout << "ClapTrap1 energyPoints: " << clapTrap1.getEnergyPoints() << std::endl;
	std::cout << "ClapTrap1 attackDamage: " << clapTrap1.getAttackDamage() << std::endl;

	clapTrap1.attack("omar");
	std::cout << "ClapTrap1 _energyPoints: " << clapTrap1.getEnergyPoints() << std::endl;

	clapTrap1.takeDamage(5);
	std::cout << "ClapTrap1 hitpoints: " << clapTrap1.getHitPoints() << std::endl;
	

	clapTrap1.takeDamage(10);
	std::cout << "ClapTrap1 hitpoints: " << clapTrap1.getHitPoints() << std::endl;

	clapTrap1.beRepaired(10);
	std::cout << "ClapTrap1 hitpoints: " << clapTrap1.getHitPoints() << std::endl;
	std::cout << "ClapTrap1 _energyPoints: " << clapTrap1.getEnergyPoints() << std::endl;

	ClapTrap	clapTrap3("test");

	for (int i = 0; i < 10; i++)
		clapTrap3.attack("dummy");
	clapTrap3.attack("dummy");
	clapTrap3.beRepaired(5);

	clapTrap3.takeDamage(100);
	clapTrap3.attack("dummy");

	return (0);
}
