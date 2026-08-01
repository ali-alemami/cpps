#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <exception>

template <typename T>
Array<T>::Array() : _arr(new T[0]), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]()), _size(n)
{}

template <typename T>
Array<T>::Array(const Array& other) : _arr(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < other._size; i++)
	{
		_arr[i] = other._arr[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _arr;
		_arr = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
		{
			_arr[i] = other._arr[i];
		}
		_size = other._size;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw (std::exception());
	return (_arr[index]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw (std::exception());
	return (_arr[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif