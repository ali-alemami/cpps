#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_count;
		int		_index;

		void		_askAndSet(Contact& contact, void (Contact::*setter)(const std::string &), const std::string& prompt);
		bool		_isNumber(const std::string& str);
		void		_showAllContacts();
		std::string	_truncate(const std::string& str, int width);

	public:
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		PhoneBook& operator=(const PhoneBook& other);
		~PhoneBook();

		void	add();
		void	search();
		void	exit();
		void	start();
};

#endif