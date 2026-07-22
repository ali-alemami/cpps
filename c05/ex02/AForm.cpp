#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <string>

AForm::AForm()
	: _name(""), _target(""), _isSigned(false), _signGrade(150), _executeGrade(150)
{}

AForm::AForm(const std::string& name, const std::string& target,
			const int signGrade, const int executeGrade)
	: _name(name), _target(target), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _target(other._target), _isSigned(other._isSigned),
	_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{}

AForm&	AForm::operator=(const AForm& other)
{
	_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() {}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade 1 is the highest grade");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade 150 is the lowest grade");
}

const char*	AForm::FormIsNotSignedException::what() const throw()
{
	return ("This form is not signed");
}

const char* AForm::BureaucratGradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is lower than the form");
}

std::string	AForm::getName() const
{
	return (_name);
}

std::string	AForm::getTarget() const
{
	return (_target);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

std::ostream&	AForm::print(std::ostream& o) const
{
	return (o << "Name: " << _name
			<< "\nTarget: " << _target
			<< "\nIs signed: " << std::boolalpha << _isSigned << std::noboolalpha
			<< "\nSign grade: " << _signGrade
			<< "\nExecute grade: " << _executeGrade);
}

std::ostream& operator<<(std::ostream& o, const AForm& x)
{
	return (x.print(o));
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw AForm::BureaucratGradeTooLowException();
}

void	AForm::isExecutable(Bureaucrat const& executor) const
{
	if (this->getIsSigned())
	{
		if (executor.getGrade() <= (*this).getExecuteGrade())
		{
			return ;
		}
		else
			throw AForm::BureaucratGradeTooLowException();
	}
	else
		throw AForm::FormIsNotSignedException();
}
