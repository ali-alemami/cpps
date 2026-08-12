#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
private:

	std::stack<int>	s;

	static bool	isoperation(const char c);
	void		operation(const char c);

public:

	RPN();
	RPN(const RPN& other);
	RPN&	operator=(const RPN& other);
	~RPN();

	int	startOperation(const std::string& str);
};

#endif