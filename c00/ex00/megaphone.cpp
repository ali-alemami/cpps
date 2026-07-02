#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	std::string	str = "";
	size_t		i = 1;

	while (argv[i])
	{
		str += argv[i];
		i++;
	}
	for (i = 0; i < str.length(); i++)
		std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
	std::cout << std::endl;
}
