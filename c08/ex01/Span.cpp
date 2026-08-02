#include "Span.hpp"

#include <vector>
#include <algorithm>

Span::Span(unsigned int num) : _v(), N(num)
{}

Span::Span(const Span& other) : _v(other._v), N(other.N)
{}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_v = other._v;
		N = other.N;
	}
	return (*this);
}

Span::~Span() {}

const char*	Span::exceededBounds::what() const throw()
{
	return ("you have exceeded N bounds.");
}

const char*	Span::tooFewElements::what() const throw()
{
	return ("too few elements.");
}

void	Span::addNumber(int num)
{
	if (N == _v.size())
		throw (Span::exceededBounds());
	_v.push_back(num);
}

int	Span::shortestSpan()
{
	if (_v.size() == 0 || _v.size() == 1)
		throw (Span::tooFewElements());

	std::vector<int>	tmp = _v;
	int					span;
	int					n;

	std::sort(tmp.begin(), tmp.end());
	span = *(tmp.begin() + 1) - *(tmp.begin());

	for (size_t i = 2; i < tmp.size(); i++)
	{
		n = *(tmp.begin() + i) - *(tmp.begin() + (i - 1));
		if (n < span)
			span = n;
	}
	return (span);
}

int	Span::longestSpan()
{
	if (_v.size() == 0 || _v.size() == 1)
	throw (Span::tooFewElements());

	std::vector<int>	tmp = _v;

	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}
