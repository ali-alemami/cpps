#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const std::string	_target;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		AForm();
		AForm(const std::string& name, const std::string& target,
			const int signGrade, const int executeGrade);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm();

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

		class FormIsNotSignedException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class BureaucratGradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		std::string				getName() const;
		std::string				getTarget() const;
		bool					getIsSigned() const;
		int						getSignGrade() const;
		int						getExecuteGrade() const;

		virtual std::ostream&	print(std::ostream& o) const;

		void					beSigned(const Bureaucrat& signer);
		void					isExecutable(Bureaucrat const& executor) const;
		virtual void			execute(Bureaucrat const& executor) const = 0;
};

std::ostream&	operator<<(std::ostream& o, const AForm& x);

#endif