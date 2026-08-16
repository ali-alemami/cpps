#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <deque>

int	main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cerr << "Error\n";
		return (1);
	}

	PmergeMe	p;
	p.mergeInsert(argv);
	
	return (0);
}
