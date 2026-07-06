#include "Contact.hpp"

Contact::Contact()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

Contact::Contact(const Contact& other)
{
	this->_firstName = other._firstName;
	this->_lastName = other._lastName;
	this->_nickName = other._nickName;
	this->_phoneNumber = other._phoneNumber;
	this->_darkestSecret = other._darkestSecret;
}

Contact& Contact::operator=(const Contact& other)
{
	if (this == &other)
		return (*this);
	this->_firstName = other._firstName;
	this->_lastName = other._lastName;
	this->_nickName = other._nickName;
	this->_phoneNumber = other._phoneNumber;
	this->_darkestSecret = other._darkestSecret;
	return (*this);
}

Contact::~Contact() {}

void Contact::setFirstName(const std::string& firstName)
{
	this->_firstName = firstName;
}
std::string Contact::getFirstName()
{
	return (this->_firstName);
}

void Contact::setLastName(const std::string& lastName)
{
	this->_lastName = lastName;
}
std::string Contact::getLastName()
{
	return (this->_lastName);
}

void Contact::setNickName(const std::string& nickName)
{
	this->_nickName = nickName;
}
std::string Contact::getNickName()
{
	return (this->_nickName);
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}
std::string Contact::getPhoneNumber()
{
	return (this->_phoneNumber);
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}
std::string Contact::getDarkestSecret()
{
	return (this->_darkestSecret);
}