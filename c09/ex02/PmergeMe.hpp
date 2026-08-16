#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>

class PmergeMe
{
private:

	std::vector<int>	v;
	std::deque<int>		q;

	int				convertStringToInt(const char* str);
	size_t			findPairSize();
	unsigned long	jacobsthal(unsigned int n);

public:

	void	pushElementsIntoContainer(char** argv);
	void	pairUpElements(int firstIndex, int secondIndex, int iterator, int level);
	void	reverseRecursive(int pairSize);
	void	mergeInsert(char **argv);
};

#endif