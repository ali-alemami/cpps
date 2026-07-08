#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string	_name;
	
	public:
		Zombie();
		Zombie(const Zombie& other);
		Zombie(const std::string& name);
		Zombie& operator=(const Zombie& other);
		~Zombie();

		void		setName(std::string name);
		std::string	getName();
		void		announce();
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

#endif