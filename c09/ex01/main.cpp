#include "RPN.hpp"

#include <iostream>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\n";
		return (1);
	}

	RPN	p;

	try
	{
		std::cout <<  p.startOperation(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error\n";
		return (1);
	}
	return (0);
}