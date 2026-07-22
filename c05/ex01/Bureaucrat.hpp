#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, const unsigned char& grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		std::string	getName() const;
		int			getGrade() const;

		void 		incrementGrade();
		void 		decrementGrade();

		void		signForm(Form& form);
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& x);

#endif