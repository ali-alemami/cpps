#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <string>

int	main()
{
	Form	form1;
	Form	form2("build a house", 1, 100);
	Form	form3(form2);

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;


	try
	{
		Form	form5("plant a tree", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Form	form6("buy water", 75, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Bureaucrat	bureaucrat1("ali", 10);

	bureaucrat1.signForm(form2);

	Form	form5("donate money", 100, 50);

	bureaucrat1.signForm(form5);
	std::cout << form5 << std::endl;

	form1 = form5;

	std::cout << form1 << std::endl;
	return (0);
}
