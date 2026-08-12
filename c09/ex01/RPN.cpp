#include "RPN.hpp"

#include <cctype>
#include <exception>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN& other) : s(other.s) {}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
		s = other.s;
	return (*this);
}

RPN::~RPN() {}

bool	RPN::isoperation(const char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

void	RPN::operation(const char c)
{
	int	x, y;

	if (s.size() < 2)
		throw (std::exception());
	else
	{
		y = s.top();
		s.pop();
		x = s.top();
		s.pop();
		switch (c)
		{
		case '+':
			s.push(x + y);
			break ;
		case '-':
			s.push(x - y);
			break ;
		case '*':
			s.push(x * y);
			break ;
		case '/':
			if (y == 0)
				throw (std::exception());
			s.push(x / y);
			break ;
		}
	}
}

int	RPN::startOperation(const std::string& str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ' || str[i] == '\t')
			continue ;
		if (isdigit(static_cast<unsigned char>(str[i])))
		{
			s.push(str[i] - '0');
		}
		else if (isoperation(str[i]))
		{
			operation(str[i]);
		}
		else
			throw(std::exception());
	}
	if (s.size() != 1)
		throw (std::exception());
	return (s.top());
}
