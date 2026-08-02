#include "easyfind.hpp"

#include <vector>
#include <iostream>
#include <list>
#include <deque>
#include <set>

int	main()
{
	int					index;
	std::vector<int>	v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);

	index = ::easyfind(v, 1);
	std::cout << " 1 was found at index: " << index << "\n";

	std::list<int>	l;
	index = ::easyfind(l, 8);
	std::cout << " 8 was found at index: " << index << "\n";

	std::deque<int>	d;
	d.push_back(4);
	d.push_back(5);
	d.push_back(4);
	index = ::easyfind(d, 4);
	std::cout << " 4 was found at index: " << index << "\n";

	std::set<int>	s;
	s.insert(0);
	s.insert(1);
	s.insert(2);
	index = ::easyfind(s, 3);
	std::cout << " 3 was not found, index: " << index << std::endl;

	return (0);
}
