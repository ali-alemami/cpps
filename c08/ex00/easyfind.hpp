#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>

template <typename T>
int	easyfind(const T& a, int b) // returns index, -1 if not found.
{
	typename T::const_iterator	it = std::find(a.begin(), a.end(), b);
	int							index = -1;

	if (it != a.end())
		index = std::distance(a.begin(), it);
	return (index);
}

#endif