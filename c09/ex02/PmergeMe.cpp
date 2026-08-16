#include "PmergeMe.hpp"

#include <cctype>
#include <exception>
#include <climits>
#include <cstdlib>
#include <string>
#include <cerrno>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstddef>

int	PmergeMe::convertStringToInt(const char* str)
{
	int		val;
	long	tmp;
	char	*endPtr;

	errno = 0;
	tmp = std::strtol(str, &endPtr, 10);
	if (tmp > INT_MAX || tmp < INT_MIN || errno == ERANGE || *endPtr != '\0')
	{
		throw (std::exception());
	}
	val = static_cast<int>(tmp);
	return (val);
}

void	PmergeMe::pushElementsIntoContainer(char** argv)
{
	int	i = 1;
	int	value;

	if (!argv || !argv[0] || !argv[1])
		throw (std::exception());
	while (argv[i])
	{
		value = convertStringToInt(argv[i]);
		v.push_back(value);
		q.push_back(value);
		i++;
	}
}


// 11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7

void	PmergeMe::pairUpElements(int firstIndex, int secondIndex, int stride, int level)
{
	if (v.size() <= 1)
		return ;
	
	int	limit;
	int	originalFirstIndex = firstIndex;
	int originalSecondIndex = secondIndex;
	int	offset;

	if (v.size() < static_cast<size_t>(1 << level))
		return ;
	limit = v.size();
	if (v.size() % stride != 0)
		limit = v.size() - (stride / 2);
	for (int i = 0; i < limit; i += stride)
	{
		if (firstIndex >= limit || secondIndex >= limit)
			break ;
		if (v[firstIndex] > v[secondIndex])
		{
			offset = stride / 2;
			while (offset != 0)
			{
				std::swap(v[firstIndex - (offset - 1)], v[secondIndex - (offset - 1)]);
				offset--;
			}
		}
		firstIndex += stride;
		secondIndex += stride;
	}
	pairUpElements(originalFirstIndex * 2 + 1, originalSecondIndex * 2 + 1, stride * 2, level + 1);
}

size_t	PmergeMe::findPairSize()
{
	size_t	pairSize = 1;

	while (static_cast<size_t>(1 << pairSize) * 3 <= v.size())
	{
		pairSize++;
	}
	return (1 << (--pairSize));
}

unsigned long	PmergeMe::jacobsthal(unsigned int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	unsigned long prev2 = 0;
	unsigned long prev1 = 1;
	unsigned long curr = 0;
	for (unsigned int i = 2; i <= n; ++i)
	{
		curr = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	return curr;
}

void	PmergeMe::reverseRecursive(int pairSize)
{
	int		lastBPair;

	lastBPair = v.size() / pairSize;
	if (lastBPair % 2 != 0)
		lastBPair++;
	int	i = 3;
	if (lastBPair >= jacobsthal(i))
	{

		int bIndex = (pairSize * 5) - 1; // (pairSize * 5) - 1 < 2^pairSize * 3; is always true
	}
}

void	PmergeMe::mergeInsert(char **argv)
{
	pushElementsIntoContainer(argv);

	pairUpElements(0, 1, 2, 1);

	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << ' ';
	}

	findPairSize();
	reverseRecursive(0);
	std::cout << "\n";
}
