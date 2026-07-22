#include "RobotomyRequestForm.hpp"

#include <string>
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("robotomy request", target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	int	r;

	AForm::isExecutable(executor);
	std::cout << "brrrrrrrt brrrrrrrrrrt whirrrrrrrr bzzzzzt\n";
	r = std::rand() % 2;
	if (r == 0)
		std::cout << (*this).getTarget() << ", you have been robotomized\n";
	else if (r == 1)
		std::cout << "the robotomy failed.\n";

}