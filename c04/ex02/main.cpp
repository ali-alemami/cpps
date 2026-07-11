#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>
#include <string>

int main()
{
	const Animal*	j = new Dog();
	const Animal*	a = new Cat();
	Dog*			k = new Dog();
	Dog*			n = new Dog();
	Animal*			zooAnimals[10];

	delete k;

	k = new Dog(*n);

	delete n;
	delete j;
	delete a;

	std::cout << k->getType() << std::endl;
	k->makeSound();

	delete k;

	for (int i = 0; i <= 4; i++)
	{
		zooAnimals[i] = new Dog();
		zooAnimals[i + 5] = new Cat();
	}

	for (int i = 0; i <= 4; i++)
	{
		delete zooAnimals[i];
		delete zooAnimals[i + 5];
	}

	return 0;
}
