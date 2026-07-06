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

		void		setFirstName(const std::string& firstName);
		std::string	getFirstName();

		void		setLastName(const std::string& lastName);
		std::string	getLastName();

		void		setNickName(const std::string& nickName);
		std::string	getNickName();

		void		setPhoneNumber(const std::string& phoneNumber);
		std::string	getPhoneNumber();

		void		setDarkestSecret(const std::string& darkestSecret);
		std::string getDarkestSecret();
};

#endif