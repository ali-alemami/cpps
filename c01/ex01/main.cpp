#include "Zombie.hpp"
#include <iostream>

int	main()
{
	Zombie	*zombies = zombieHorde(10, "ali");
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << ": ";
		zombies[i].announce();
	}
	delete [] zombies;
	return (0);
}