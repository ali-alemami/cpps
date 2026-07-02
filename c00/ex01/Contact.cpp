#include "Contact.hpp"

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		Contact()
		{
			this->_firstName = "";
			this->_lastName = "";
			this->_nickName = "";
			this->_phoneNumber = "";
			this->_darkestSecret = "";
		}

		Contact(const Contact& other)
		{
			this->_firstName = other._firstName;
			this->_lastName = other._lastName;
			this->_nickName = other._nickName;
			this->_phoneNumber = other._phoneNumber;
			this->_darkestSecret = other._darkestSecret;
		}

		Contact& operator=(const Contact& other)
		{
			this->_firstName = other._firstName;
			this->_lastName = other._lastName;
			this->_nickName = other._nickName;
			this->_phoneNumber = other._phoneNumber;
			this->_darkestSecret = other._darkestSecret;
			return (*this);
		}

		~Contact() {}

		void		setFirstName(std::string firstName)
		{
			this->_firstName = firstName;
		}
		std::string	getFristName()
		{
			return (this->_firstName);
		}

		void		setLastName(std::string lastName)
		{
			this->_lastName = lastName;
		}
		std::string	getLastName()
		{
			return (this->_lastName);
		}

		void		setNickName(std::string nickName)
		{
			this->_nickName = nickName;
		}
		std::string	getNickName()
		{
			return (this->_nickName);
		}

		void		setPhoneNumber(std::string phoneNumber)
		{
			this->_phoneNumber = phoneNumber;
		}
		std::string	getPhoneNumber()
		{
			return (this->_phoneNumber);
		}

		void		setDarkestSecret(std::string darkestSecret)
		{
			this->_darkestSecret = darkestSecret;
		}
		std::string getDarkestSecret()
		{
			return (this->_darkestSecret);
		}
};
