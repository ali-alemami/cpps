#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}
	return (zombies);
}
