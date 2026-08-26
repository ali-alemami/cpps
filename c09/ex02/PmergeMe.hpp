#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>
#include <string>
#include <exception>

class PmergeMe
{
private:
	// ---- std::vector Containers ----
	std::vector<int>    v;
	std::vector<int>    mainChain;
	std::vector<int>    pendChain;
	std::vector<int>    extra;

	// ---- std::deque Containers ----
	std::deque<int>     q;
	std::deque<int>     mainChainQ;
	std::deque<int>     pendChainQ;
	std::deque<int>     extraQ;

	// ---- Shared Helper Methods ----
	int     convertStringToInt(const char* str);
	size_t  jacobsthal(size_t index);

	// ---- std::vector Methods ----
	void    pairUpElements(size_t firstIndex, size_t secondIndex, size_t pairSize, size_t level);
	void    moveBlocksToChain(std::vector<int>::iterator& it, size_t pairSize,
				size_t& totalBlocks, bool toPendChain);
	void    splitIntoPendAndMain(size_t pairSize, size_t totalBlocks);
	void    unwindAndInsert(size_t pairSize);

	// ---- std::deque Methods ----
	void    pairUpElementsDeque(size_t firstIndex, size_t secondIndex, size_t pairSize, size_t level);
	void    moveBlocksToChainDeque(std::deque<int>::iterator& it, size_t pairSize,
				size_t& totalBlocks, bool toPendChain);
	void    splitIntoPendAndMainDeque(size_t pairSize, size_t totalBlocks);
	void    unwindAndInsertDeque(size_t pairSize);

public:
	// ---- Orthodox Canonical Form ----
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	// ---- Public Interface ----
	void    pushElementsIntoContainer(char** argv);
	void    mergeInsertVector();
	void    mergeInsertDeque();

	// ---- Getters ----
	const std::vector<int>&	getVector() const;
	const std::deque<int>&	getDeque() const;

	// ---- Exception Classes ----
	class InvalidInputException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif