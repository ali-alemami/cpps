#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int	main()
{
	std::srand(std::time(0));

	Intern	random;
	AForm*	rrf;
	
	rrf = random.makeForm("robotomy request", "Bender");
	if (!rrf)
		return (1);
	std::cout << *rrf << "\n\n";

	Bureaucrat	b1("ali", 5);
	b1.signForm(*rrf);
	std::cout << *rrf << "\n";
	b1.executeForm(*rrf);
	std::cout << "\n";

	AForm* rrf2 = random.makeForm("shrubbery creation", "Bender");
	if (!rrf2)
	{
		delete rrf;
		return (1);
	}
	AForm* rrf3 = random.makeForm("presidential pardon", "Bender");
	if (!rrf3)
	{
		delete rrf;
		delete rrf2;
		return (1);
	}


	std::cout << *rrf2 << "\n\n" << *rrf3 << "\n\n";
	b1.signForm(*rrf2);
	std::cout << "\n";
	b1.executeForm(*rrf2);
	std::cout << "\n";

	b1.signForm(*rrf3);
	std::cout << "\n";
	b1.executeForm(*rrf3);
	std::cout << "\n";

	delete rrf;
	delete rrf2;
	delete rrf3;
	return (0);
}
