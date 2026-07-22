#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int	main()
{
	std::srand(std::time(0));

	ShrubberyCreationForm	form1("ali");	// 145	137
	RobotomyRequestForm		form2("omar");	// 72	45
	PresidentialPardonForm	form3("sarah");	// 25	5
	
	std::cout << form1 << "\n\n";
	std::cout << form2 << "\n\n";
	std::cout << form3 << "\n\n";

	Bureaucrat	b1("xin", 73);
	Bureaucrat	b2("lee", 1);

	b1.executeForm(form2);
	b1.signForm(form2);
	b1.incrementGrade();
	b1.signForm(form2);
	b1.executeForm(form2);

	std::cout << "\n\n";
	b2.signForm(form2);
	b2.executeForm(form2);

	std::cout << "\n\n";
	b2.executeForm(form1);
	b2.signForm(form1);
	b2.executeForm(form1);

	std::cout << "\n\n";
	b2.signForm(form3);
	b2.executeForm(form3);

	return (0);
}
