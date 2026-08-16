#include "PhoneBook.hpp"

void	PhoneBook::_askAndSet(Contact& contact, void (Contact::*setter)(const std::string &), const std::string& prompt)
{
	std::string	input;
	do
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::exit(0);
	} while (input.empty());
	(contact.*setter)(input);
}

bool	PhoneBook::_isNumber(const std::string& str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

PhoneBook::PhoneBook()
	: _count(0), _index(0)
{}

PhoneBook::PhoneBook(const PhoneBook& other)
{
	for (int i = 0; i <= 7; i++)
		this->_contacts[i] = other._contacts[i];
	this->_count = other._count;
	this->_index = other._index;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i <= 7; i++)
		this->_contacts[i] = other._contacts[i];
	this->_count = other._count;
	this->_index = other._index;
	return (*this);
}

PhoneBook::~PhoneBook() {}


void	PhoneBook::add()
{
	_askAndSet(_contacts[_index], &Contact::setFirstName, "First name: ");
	_askAndSet(_contacts[_index], &Contact::setLastName, "Last name: ");
	_askAndSet(_contacts[_index], &Contact::setNickName, "Nick name: ");
	do 
	{
		_askAndSet(_contacts[_index], &Contact::setPhoneNumber, "Phone number: ");
		if (!_isNumber(_contacts[_index].getPhoneNumber())
				|| _contacts[_index].getPhoneNumber().substr(0, 2) != "07"
				|| _contacts[_index].getPhoneNumber().size() != 10)
			std::cout << "Phone number must start with 07 and be 10 digits" << std::endl;
	} while (!_isNumber(_contacts[_index].getPhoneNumber())
				|| _contacts[_index].getPhoneNumber().substr(0, 2) != "07"
				|| _contacts[_index].getPhoneNumber().size() != 10);
	_askAndSet(_contacts[_index], &Contact::setDarkestSecret, "Darkest secret: ");
	_index++;
	_index %= 8;
	if (_count < 8)
		_count++;
}

std::string	PhoneBook::_truncate(const std::string& str, int width)
{
	if ((int)str.size() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

void	PhoneBook::_showAllContacts()
{
	if (_count == 0)
	{
		std::cout << std::endl << "    There are no available contacts" << std::endl << std::endl;
		return ;
	}
	std::cout << std::right << std::setw(10) << "index" << "|";
	std::cout << std::right << std::setw(10) << "first name" << "|";
	std::cout << std::right << std::setw(10) << "last name" << "|";
	std::cout << std::right << std::setw(10) << "nickname" << "|";
	std::cout << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << _truncate(_contacts[i].getFirstName(), 10) << "|";
		std::cout << std::right << std::setw(10) << _truncate(_contacts[i].getLastName(), 10) << "|";
		std::cout << std::right << std::setw(10) << _truncate(_contacts[i].getNickName(), 10) << "|";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::search()
{
	int	n;

	_showAllContacts();
	if (_count == 0)
		return ;
	std::string	input;
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		std::exit(0);
	std::stringstream ss(input);
	ss >> n;
	if (!_isNumber(input) || (n < 0 || n >= _count))
	{
		std::cout << "this index doesn't exist!" << std::endl;
		return ;
	}
	std::cout << "\033[2J\033[1;1H" << std::endl;
	std::cout << " First name: " << _contacts[n].getFirstName() << std::endl;
	std::cout << " Last name: " << _contacts[n].getLastName() << std::endl;
	std::cout << " Nickname: " << _contacts[n].getNickName() << std::endl;
	std::cout << " Phone number: " << _contacts[n].getPhoneNumber() << std::endl;
	std::cout << " Darkest secret: " << _contacts[n].getDarkestSecret() << std::endl << std::endl;
}

void	PhoneBook::exit()
{
	std::exit(0);
}

void	PhoneBook::start()
{
	std::string	input;
	do
	{
		std::cout << "Choose one of the options: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input == "ADD")
			add();
		else if (input == "SEARCH")
			search();
		else if (input == "EXIT")
			exit();
	} while (true);
}