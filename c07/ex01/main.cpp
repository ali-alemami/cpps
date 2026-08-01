#include "iter.hpp"

#include <iostream>

void	printInt(const int e)
{
	std::cout << e << "\n";
}

template <typename T>
void	printAny(T e)
{
	std::cout << e << "\n";
}

void addOne(int &e) { e++; }

int	main()
{
	int	arr[10] = {0};

	::iter(arr, 10, printInt);

	std::cout << "\n\n";

	::iter(arr, 10, printAny<int>);

	::iter(arr, 10, addOne);

	::iter(arr, 10, printInt);

	return (0);
}