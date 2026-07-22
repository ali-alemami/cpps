#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	int	idx = -1;
	const std::string	formArr[3]
	= {"presidential pardon", "robotomy request", "shrubbery creation"};
	
	for (int i = 0; i <= 2; i++)
	{
		if (name == formArr[i])
		{
			idx = i;
			break ;
		}
	}
	switch (idx)
	{
	case 0:
		std::cout << "Intern creates presidential pardon\n";
		return (new PresidentialPardonForm(target));
	case 1:
		std::cout << "Intern creates robotomy request\n";
		return (new RobotomyRequestForm(target));
	case 2:
		std::cout << "Intern creates shrubbery creation\n";
		return (new ShrubberyCreationForm(target));
	default:
		std::cerr << "the provided form name does not exist!\n";
		return (NULL);
	}
}
