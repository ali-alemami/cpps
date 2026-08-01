#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void	iter(T *arr, const unsigned long int length, F elementOperation)
{
	for (unsigned long int i = 0; i < length; i++)
	{
		elementOperation(arr[i]);
	}
}

#endif