#include "BitcoinExchange.hpp"

#include <string>
#include <climits>
#include <ctime>
#include <map>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : m(other.m)
{}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->m = other.m;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

int	BitcoinExchange::convertStringToInt(const std::string& str)
{
	int		val;
	long	tmp;
	char	*endPtr;

	errno = 0;
	tmp = std::strtol(str.c_str(), &endPtr, 10);
	if (tmp > INT_MAX || tmp < INT_MIN || errno == ERANGE || *endPtr != '\0')
	{
		throw (std::exception());
	}
	val = static_cast<int>(tmp);
	return (val);
}

double	BitcoinExchange::convertStringToDouble(const std::string& str)
{
	double	val;
	char	*endPtr;
	
	errno = 0;
	val = std::strtod(str.c_str(), &endPtr);
	if (errno == ERANGE || *endPtr != '\0')
	{
		throw (std::exception());
	}
	return (val);
}

void	BitcoinExchange::loadDataBase(const std::string& fileName)
{
	std::ifstream					infile;
	std::string						line;
	tm								date;
	double							exchangeRate;

	infile.open(fileName.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open file.\n";
		exit(1);
	}
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		date.tm_year = convertStringToInt(line.substr(0, 4)) - 1900;
		date.tm_mon = convertStringToInt(line.substr(5, 2)) - 1;
		date.tm_mday = convertStringToInt(line.substr(8, 2));
		exchangeRate = convertStringToDouble(line.substr(11));
		m[date] = exchangeRate;
	}
	infile.close();
}

std::ostream&	operator<<(std::ostream& o, const tm& date)
{
	o << date.tm_year + 1900 << "-"
	<< std::setfill('0') << std::setw(2) << date.tm_mon + 1 << "-"
	<< std::setfill('0') << std::setw(2) << date.tm_mday;
	return (o);
}

bool	BitcoinExchange::findClosestMatchingDate(tm date, double& exchangeRate)
{
	std::map<tm, double, TmCompare>::iterator	it;
	std::map<tm, double, TmCompare>::iterator	begin = m.begin();
	TmCompare									cmp;

	if (cmp(date, begin->first))
			return (false);
	while (true)
	{
		it = m.find(date);
		if (it != m.end())
		{
			exchangeRate = it->second;
			return (true);
		}
		date.tm_mday--;
		mktime(&date);
	}
}

void	BitcoinExchange::isValidDate(tm date)
{
	tm	tmp = date;
	mktime(&date);
	if (tmp.tm_year == date.tm_year && tmp.tm_mon == date.tm_mon
		&& tmp.tm_mday == date.tm_mday)
		return ;
	throw (std::exception());
}

void	BitcoinExchange::parseLine(const std::string& line, tm& date, double& value)
{
	if (line.size() < 14)
		throw (std::exception());
	if (line[4] != '-' || line[7] != '-' || line.substr(10, 3) != " | ")
		throw (std::exception());
	date.tm_year = convertStringToInt(line.substr(0, 4)) - 1900;
	date.tm_mon = convertStringToInt(line.substr(5, 2)) - 1;
	date.tm_mday = convertStringToInt(line.substr(8, 2));
	isValidDate(date);
	value = convertStringToDouble(line.substr(13));
}

void	BitcoinExchange::evaluateAndPrint(const tm& date, double value)
{
	double	exchangeRate = 0;

	if (value > 1000)
	{
		std::cerr << "Error: too large a number.\n";
		return ;
	}
	if (value < 0)
	{
		std::cerr << "Error: not a positive number.\n";
		return ;
	}
	if (findClosestMatchingDate(date, exchangeRate))
		std::cout << date << " => " << value << " = " << exchangeRate * value + 0.0 << "\n";
	else
		std::cerr << "Error: date was not found => " << date << "\n";
}

void	BitcoinExchange::processInputFile(const std::string& fileName)
{
	std::ifstream	infile;
	std::string		line;
	tm				date = tm();
	double			value;

	std::cout << std::setprecision(15);

	infile.open(fileName.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open file.\n";
		return ;
	}
	std::getline(infile, line);
	if (line != "date | value")
	{
		std::cerr << "Error: wrong format => " << line << "\n";
		return ;
	}
	while (std::getline(infile, line))
	{
		if (line.empty())
			continue ;
		try
		{
			parseLine(line, date, value);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: bad input => " << line << "\n";
			continue ;
		}
		evaluateAndPrint(date, value);
	}
	infile.close();
}
