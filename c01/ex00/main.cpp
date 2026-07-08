#include "Zombie.hpp"
#include <iostream>

int	main()
{
	Zombie	*zombie2 = newZombie("ali");
	zombie2->announce();
	delete zombie2;
	randomChump("ali2");
	return (0);
}
