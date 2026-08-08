#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << "\n\n";

	///////////////////////////////////////////////////////////////

	std::deque<int> deque;

	deque.push_back(5);
	deque.push_back(17);

	std::cout << deque.back() << std::endl;

	deque.pop_back();

	std::cout << deque.size() << std::endl;

	deque.push_back(3);
	deque.push_back(5);
	deque.push_back(737);
	//[...]
	deque.push_back(0);

	std::deque<int>::iterator dit = deque.begin();
	std::deque<int>::iterator dite = deque.end();

	++dit;
	--dit;

	while (dit != dite)
	{
		std::cout << *dit << std::endl;
		++dit;
	}

	std::stack<int> d(deque);

	return 0;
}
