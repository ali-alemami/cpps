#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void)
{
	int	r = std::rand() % 3;

	switch (r)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	default:
		return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "this is class A\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "this is class B\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "this is class C\n";
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "this is class A\n";
	}
	catch(const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "this is class B\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "this is class C\n";
			}
			catch(const std::exception& e)
			{
				return ;
			}
		}
	}
}

int	main()
{
	std::srand(std::time(NULL));

	Base*	p = generate();
	identify(p);

	A	q;
	B	w;
	C	e;

	Base&	b1 = q;
	Base&	b2 = w;
	Base&	b3 = e;

	identify(b1);
	identify(b2);
	identify(b3);

	delete p;
	return (0);
}