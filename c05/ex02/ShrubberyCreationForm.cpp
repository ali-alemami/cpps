#include "ShrubberyCreationForm.hpp"

#include <string>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	AForm::isExecutable(executor);
	std::ofstream file(((*this).getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("could not create file");
	file << "     *          /\\\n";
	file << "    ***        /  \\\n";
	file << "   *****      /    \\\n";
	file << "  *******    /------\\\n";
	file << "     |         ||||\n";
	file.close();
}
