#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

int	main()
{
	Bureaucrat	b3("zoe", 42);
	Bureaucrat	b4(b3);
	Bureaucrat	b5("temp", 111);
	
	b5 = b3;
	std::cout << b4 << std::endl << b5 << std::endl;

	try
	{
		Bureaucrat	b1("ali", 1);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	b1("ali 2", 150);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat	b1("ali 3", 0);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat	b1("omar", 1);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << "you can't see me" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat b2("sara", 150);
		b2.decrementGrade();   // should throw, already at 150
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}