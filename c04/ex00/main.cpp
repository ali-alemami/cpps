#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>
#include <string>

int main()
{
	const Animal*	animal1 = new Animal();
	const Animal*	animal2 = new Dog();
	const Animal*	animal3 = new Cat();

	const Dog*		animal4 = new Dog();

	const Animal	animal7(*animal1);

	std::cout << animal7.getType() << " " << std:: endl;
	animal7.makeSound();

	Animal		animal9;
	Dog			animal10;

	animal9 = *animal4;
	animal10 = *animal4;

	std::cout << animal9.getType() << " " << std::endl;
	animal9.makeSound();
	
	std::cout << animal10.getType() << " " << std::endl;

	const WrongAnimal* animal11 = new WrongCat();

	std::cout << animal11->getType() << " " << std::endl;
	animal11->makeSound();

	std::cout << animal2->getType() << " " << std::endl;
	std::cout << animal3->getType() << " " << std:: endl;
	animal3->makeSound(); //will output the cat sound!
	animal2->makeSound();
	animal1->makeSound();

	std::cout << animal4->getType() << " " << std::endl;
	animal4->makeSound();

	delete animal1;
	delete animal2;
	delete animal3;
	delete animal4;

	delete animal11; // NOTE: WrongAnimal's destructor isn't virtual — this is
        		// undefined behavior by design, to demonstrate why base
        		// classes meant for polymorphism need a virtual destructor.

	return 0;
}
