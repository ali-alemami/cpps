#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#include <string>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon Form", target, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other)
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	AForm::isExecutable(executor);
	std::cout << (*this).getTarget()
			<< ", you have been pardoned by Zaphod Beeblebrox.\n";
}
