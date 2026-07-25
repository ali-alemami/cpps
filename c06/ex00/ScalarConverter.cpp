#include "ScalarConverter.hpp"

#include <string>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cctype>

enum eTypes {CHAR, INT, FLOAT, DOUBLE};

static bool	isIntLiterals(const std::string& str)
{
	size_t	i = 0;

	if (str.empty())
		return (false);
	if (str.size() > 1 && (str[0] == '-' || str[0] == '+') && std::isdigit(static_cast<unsigned char>(str[1])))
		i++;
	for(;i < str.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

static bool	isFloatLiterals(const std::string& str)
{
	size_t	i = 0;
	bool	pointFlag = false, fFlag = false, digitFlag = false;
	if (str.empty())
		return (false);
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	if (str[0] == '-' || str[0] == '+')
		i++;
	for(; i < str.size(); i++)
	{
		if (std::isdigit(static_cast<unsigned char>(str[i])))
			digitFlag = true;
		else if (str[i] == '.' && !pointFlag)
			pointFlag = true;
		else if (str[i] == 'f' && i + 1 == str.size())
			fFlag = true;
		else
			return (false);
	}
	if (!pointFlag || !fFlag || !digitFlag)
		return (false);
	return (true);
}

static bool	isDoubleLiterals(const std::string& str)
{
	size_t	i = 0;
	bool	pointFlag = false, digitFlag = false;

	if (str.empty())
		return (false);
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	if (str[0] == '-' || str[0] == '+')
		i++;
	for(; i < str.size(); i++)
	{
		if (std::isdigit(static_cast<unsigned char>(str[i])))
			digitFlag = true;
		else if (str[i] == '.' && !pointFlag)
			pointFlag = true;
		else
			return (false);
	}
	if (!pointFlag || !digitFlag)
		return (false);
	return (true);
}

static eTypes	findType(const std::string& str)
{
	if (isIntLiterals(str))
		return (INT);
	else if (isFloatLiterals(str))
		return (FLOAT);
	else if (isDoubleLiterals(str))
		return (DOUBLE);
	return (CHAR);
}

static std::string	formatFloatingPoint(double value, bool isFloat)
{
	std::ostringstream	oss;
	if (isFloat)
		oss << std::fixed << std::setprecision(7) << value;
	else
		oss << std::fixed << std::setprecision(17) << value;
	std::string	str = oss.str();
	while (str[str.size() - 1] == '0' && str[str.size() - 2] != '.')
			str.erase(str.size() - 1, 1);
	if (isFloat)
		str += "f";
	return (str);
}

static void	print(char c, int i, float f, double d,
							int impossible, int nonDisplayable)
{
	if (impossible & 1)
		std::cout << "char: impossible\n";
	else if (nonDisplayable)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'\n";
	if (impossible >> 1 & 1)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << i << "\n";
	if (impossible >> 2 & 1)
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " << formatFloatingPoint(f, true) << "\n";
	if (impossible >> 3 & 1)
		std::cout << "double: impossible\n";
	else
		std::cout << "double: " << formatFloatingPoint(d, false) << "\n";
}

static void	strToChar(const std::string& str)
{
	char		c;
	int			i;
	float		f;
	double		d;

	if (str.size() != 1)
	{
		print(0, 0, 0.0f, 0.0, 15, 0);
		return ;
	}
	c = str[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	print(c, i, f, d, 0, !std::isprint(static_cast<unsigned char>(c)));
}

static void		strToInt(const std::string& str)
{
	char	c;
	int		i;
	float	f;
	double	d;
	long	temp;
	int		impossible = 0;
	int		nonDisplayable = 0;

	errno = 0;
	temp = std::strtol(str.c_str(), NULL, 10);
	if (temp > INT_MAX || temp < INT_MIN || errno == ERANGE)
	{
		print(0, 0, 0.0f, 0.0, 15, 0);
		return ;
	}
	i = static_cast<int>(temp);
	if (i < CHAR_MIN || i > CHAR_MAX)
	{
		impossible = 1;
		c = 0;
	}
	else
	{
		c = static_cast<char>(i);
		if (!std::isprint(static_cast<unsigned char>(c)))
			nonDisplayable = 1;
	}
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	print(c, i, f, d, impossible, nonDisplayable);
}

static void		strToFloat(const std::string& str)
{
	char	c;
	int		i;
	float	f;
	double	d;
	int		impossible = 0;
	int		nonDisplayable = 0;
	double	temp;

	temp = std::strtod(str.c_str(), NULL);
	f = static_cast<float>(temp);
	if ((f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity())
	&& (str != "-inff" && str != "+inff" && str != "nanf"))
	{
		print(0, 0, 0.0f, 0.0, 15, 0);
		return ;
	}
	f = static_cast<float>(temp);
	if (static_cast<double>(f) <= static_cast<double>(CHAR_MIN) - 1.0
	|| static_cast<double>(f) >= static_cast<double>(CHAR_MAX) + 1.0
	|| str == "-inff" || str == "+inff" || str == "nanf")
	{
		impossible = 1;
		c = 0;
	}
	else
	{
		c = static_cast<char>(f);
		if (!std::isprint(static_cast<unsigned char>(c)))
			nonDisplayable = 1;
	}
	if (static_cast<double>(f) <= static_cast<double>(INT_MIN) - 1.0
	|| static_cast<double>(f) >= static_cast<double>(INT_MAX) + 1.0
	|| str == "-inff" || str == "+inff" || str == "nanf")
	{
		impossible += 2;
		i = 0;
	}
	else
		i = static_cast<int>(f);
	d = static_cast<double>(f);
	print(c, i, f, d, impossible, nonDisplayable);
}

static void	strToDouble(const std::string& str)
{
	char	c;
	int		i;
	float	f;
	double	d;
	int		impossible = 0;
	int		nonDisplayable = 0;

	errno = 0;
	d = std::strtod(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		print(0, 0, 0.0f, 0.0, 15, 0);
		return ;
	}
	if (d <= static_cast<double>(CHAR_MIN) - 1.0
	|| d >= static_cast<double>(CHAR_MAX) + 1.0
	|| str == "-inf" || str == "+inf" || str == "nan")
	{
		impossible = 1;
		c = 0;
	}
	else
	{
		c = static_cast<char>(d);
		if (!std::isprint(static_cast<unsigned char>(c)))
			nonDisplayable = 1;
	}
	if (d <= static_cast<double>(INT_MIN) - 1.0
	|| d >= static_cast<double>(INT_MAX) + 1.0
	|| str == "-inf" || str == "+inf" || str == "nan")
	{
		impossible += 2;
		i = 0;
	}
	else
		i = static_cast<int>(d);
	f = static_cast<float>(d);
	if ((f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity())
	&& (str != "inf" && str != "+inf" && str != "-inf"))
	{
		impossible += 4;
		f = 0.0f;
	}
	else
		f = static_cast<float>(d);
	print(c, i, f, d, impossible, nonDisplayable);
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{ (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string& str)
{
	eTypes	type = findType(str);
	switch (type)
	{
	case CHAR:
		strToChar(str);
		break;
	case INT:
		strToInt(str);
		break ;
	case FLOAT:
		strToFloat(str);
		break ;
	case DOUBLE:
		strToDouble(str);
		break ;
	default:
		break;
	}
}
