#include "PmergeMe.hpp"
#include <cctype>
#include <climits>
#include <cstdlib>
#include <cerrno>

// =============================================================================
// Orthodox Canonical Form
// =============================================================================

PmergeMe::PmergeMe() 
{
}

PmergeMe::PmergeMe(const PmergeMe& other) 
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{
	if (this != &other)
	{
		this->v = other.v;
		this->mainChain = other.mainChain;
		this->pendChain = other.pendChain;
		this->extra = other.extra;

		this->q = other.q;
		this->mainChainQ = other.mainChainQ;
		this->pendChainQ = other.pendChainQ;
		this->extraQ = other.extraQ;
	}
	return *this;
}

PmergeMe::~PmergeMe() 
{
}

// =============================================================================
// Exception Handling
// =============================================================================

const char*	PmergeMe::InvalidInputException::what() const throw() 
{
	return "Error";
}

// =============================================================================
// Shared Helpers
// =============================================================================

int PmergeMe::convertStringToInt(const char* str)
{
	int     val;
	long    tmp;
	char    *endPtr;

	errno = 0;
	tmp = std::strtol(str, &endPtr, 10);
	if (tmp > INT_MAX || tmp <= 0 || errno == ERANGE || *endPtr != '\0' || endPtr == str)
	{
		throw PmergeMe::InvalidInputException();
	}
	val = static_cast<int>(tmp);
	return val;
}

size_t PmergeMe::jacobsthal(size_t index)
{
	size_t  prev = 0;
	size_t  current = 1;
	size_t  tmp;
	size_t  i = 1;

	if (index == 0)
		return 0;
	while (i < index)
	{
		tmp = current + (2 * prev);
		prev = current;
		current = tmp;
		i++;
	}
	return current;
}

// =============================================================================
// Input Parsing
// =============================================================================

void    PmergeMe::pushElementsIntoContainer(char** argv)
{
	size_t i = 1;
	int value;

	if (!argv || !argv[0] || !argv[1])
		throw PmergeMe::InvalidInputException();
		
	while (argv[i])
	{
		value = convertStringToInt(argv[i]);
		v.push_back(value);
		q.push_back(value);
		i++;
	}
}

// =============================================================================
// Getters
// =============================================================================

const std::vector<int>&	PmergeMe::getVector() const
{
	return v;
}

const std::deque<int>&	PmergeMe::getDeque() const
{
	return q;
}
