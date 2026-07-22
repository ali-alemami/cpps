#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <string>
#include <iostream>

Bureaucrat::Bureaucrat() : _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, const unsigned char& grade)
	: _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade 1 is the highest grade");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade 150 is the lowest grade");
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName()
				<< " because " << e.what() << ".\n";
	}
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << (*this).getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName()
				<< " because " << e.what() << ".\n";
	}
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& x)
{
	o << x.getName() << ", bureaucrat grade " << x.getGrade() << ".";
	return (o);
}
