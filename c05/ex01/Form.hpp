#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		Form();
		Form(const std::string& name, const int signGrade, const int executeGrade);
		Form(const Form& other);
		Form&	operator=(const Form& other);
		~Form();

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
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		void		beSigned(const Bureaucrat& bureaucrat);
};

std::ostream&	operator<<(std::ostream& o, const Form& x);

#endif