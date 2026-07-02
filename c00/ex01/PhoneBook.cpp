#include "PhoneBook.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_count;

		void	askAndSet(Contact& contact,
				void (Contact::*setter)(std::string), const std::string& prompt)
		{
			std::string	input;
			do
			{
				std::cout << prompt;
				std::getline(std::cin, input);
			} 	while (input.empty());
			(contact.*setter)(input);
		}
	public:
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		PhoneBook& operator=(const PhoneBook& other);
		~PhoneBook();
		
		void	add(int i)
		{
			askAndSet(_contacts[i], &Contact::setFirstName, "First name: ");
			askAndSet(_contacts[i], &Contact::setLastName, "Last name: ");
			askAndSet(_contacts[i], &Contact::setNickName, "Nick name: ");
			askAndSet(_contacts[i], &Contact::setPhoneNumber, "Phone number: ");
			askAndSet(_contacts[i], &Contact::setDarkestSecret, "Darkest secret: ");
		}
		void	search()
		{
			std::cout << std::right << std::setw(10) << "index|";
			std::cout << std::right << std::setw(10) << "fist name|";
			std::cout << std::right << std::setw(10) << "last name|";
			std::cout << std::right << std::setw(10) << "nickname|";
			std::cout << std::endl;
			for (int i = 0; i <= 7; i++)
			{
				std::cout << std::right << std::setw(10) << i;
				std::cout << std::right << std::setw(10) << _contacts[i].getFristName();
				std::cout << std::right << std::setw(10) << _contacts[i].getLastName();
				std::cout << std::right << std::setw(10) << _contacts[i].getNickName();
				std::cout << std::endl;
			}
		}

		void	exit();
};
