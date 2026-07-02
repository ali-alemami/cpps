#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		Contact();
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
		~Contact();

		void		setFirstName(std::string firstName);
		std::string	getFristName();

		void		setLastName(std::string lastName);
		std::string	getLastName();

		void		setNickName(std::string lastName);
		std::string	getNickName();

		void		setPhoneNumber(std::string phoneNumber);
		std::string	getPhoneNumber();

		void		setDarkestSecret(std::string darkestSecret);
		std::string getDarkestSecret();
};

#endif