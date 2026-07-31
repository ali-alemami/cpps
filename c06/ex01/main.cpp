#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>
#include <stdint.h>

int	main()
{
	Data*		d1 = new Data(10);

	Data*	d2 = Serializer::deserialize(Serializer::serialize(d1));

	if (d1 == d2)
		std::cout << "correct!!!\n\n";

	delete d1;
	return (0);
}