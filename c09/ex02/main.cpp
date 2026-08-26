#include "PmergeMe.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>

template <typename Container>
static void	printContainer(const Container& c)
{
	typename Container::const_iterator it = c.begin();
	while (it != c.end())
	{
		std::cout << *it;
		++it;
		if (it != c.end())
			std::cout << " ";
	}
}

int	main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	try
	{
		PmergeMe	p;

		p.pushElementsIntoContainer(argv);

		std::cout << "Before: ";
		printContainer(p.getVector());
		std::cout << std::endl;

		clock_t	startVec = clock();
		p.mergeInsertVector();
		clock_t	endVec = clock();

		clock_t	startDeq = clock();
		p.mergeInsertDeque();
		clock_t	endDeq = clock();

		std::cout << "After: ";
		printContainer(p.getVector());
		std::cout << std::endl;

		// clock returns how many CPU "ticks" my program has used so far. so we do 2 
		// snapshots before and after the algorithm. CLOCKS_PER_SEC is a macro that tells me
		// how many ticks = 1 seconds on my system. so am dividing by it to conver ticks to seconds.

		double	timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
		double	timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

		std::cout << "Time to process a range of " << std::setw(5) << argc - 1
			<< " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
		std::cout << "Time to process a range of " << std::setw(5) << argc - 1
			<< " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
