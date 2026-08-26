#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <ostream>
#include <ctime>

class BitcoinExchange
{
private:

	struct TmCompare
	{
		bool	operator()(const tm& a, const tm& b) const;
	};

	std::map<tm, double, TmCompare>	m;
	
	static int		convertStringToInt(const std::string& str);
	static double	convertStringToDouble(const std::string& str);
	bool			findClosestMatchingDate(tm date, double& exchangeRate);
	static void		isValidDate(tm date);
	static void		parseLine(const std::string& line, tm& date, double& value);
	void			evaluateAndPrint(const tm& date, double value);

public:

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange&	operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void			loadDataBase(const std::string& fileName);
	void			processInputFile(const std::string& fileName);
};

std::ostream&	operator<<(std::ostream& o, const tm& date);

#endif