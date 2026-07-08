#include "Harl.hpp"
#include <string>
#include <iostream>

int	main(int argc, char **argv)
{
	enum		eLevels { DEBUG, INFO, WARNING, ERROR };
	std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	std::string	level;
	Harl		harl;
	eLevels		eLevel;

	if (argc != 2)
		return (0);
	level = argv[1];
	for (int i = 0; i <= 3; i++)
	{
		if (level == levels[i])
		{
			eLevel = static_cast<eLevels>(i);
			break ;
		}
		eLevel = static_cast<eLevels>(4);
	}
	switch (eLevel)
	{
	case DEBUG:
		std::cout << "[ DEBUG ]" << std::endl;
		harl.debug();
		std::cout << std::endl;
		// fallthrough
	case INFO:
		std::cout << "[ INFO ]" << std::endl;
		harl.info();
		std::cout << std::endl;
		// fallthrough
	case WARNING:
		std::cout << "[ WARNING ]" << std::endl;
		harl.warning();
		std::cout << std::endl;
		//fallthrough
	case ERROR:
		std::cout << "[ ERROR ]" << std::endl;
		harl.error();
		std::cout << std::endl;
		//fallthrough
	default:
		break;
	}
}
