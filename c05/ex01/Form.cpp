#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <string>

Form::Form()
	: _isSigned(false), _signGrade(150), _executeGrade(150)
{}

Form::Form(const std::string& name, const int signGrade, const int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned),
	_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{}

Form&	Form::operator=(const Form& other)
{
	_isSigned = other._isSigned;
	return (*this);
}

Form::~Form() {}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade 1 is the highest grade");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade 150 is the lowest grade");
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecuteGrade() const
{
	return (_executeGrade);
}

std::ostream& operator<<(std::ostream& o, const Form& x)
{
	return (o << x.getName() << ", is signed: " << std::boolalpha << x.getIsSigned()
			<< std::noboolalpha << ".\n" << "Sign grade: " << x.getSignGrade()
			<< ", execute grade: " << x.getExecuteGrade());
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}
