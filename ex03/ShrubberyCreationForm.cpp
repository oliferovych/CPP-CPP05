/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:33:08 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/05 18:06:17 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	if(this == &other)
		return;
	_target = other._target;
}

//Operator "=" overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this == &other)
		return *this;
	AForm::operator=(other);
	_target = other._target;
	return *this;
}

//Deconstructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

//Getters
std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

//Methods
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::ofstream file;
	file.open((_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	if (!file.is_open())
		throw std::runtime_error("Error: file could not be opened.");
	for(int i = 0; i < 5; i++)
	{
		file << "       _-_\n"
    	        "    /~~   ~~\\\n"
    	        " /~~         ~~\\\n"
    	        "{               }\n"
    	        " \\  _-     -_  /\n"
    	        "   ~  \\\\ //  ~\n"
    	        "_- -   | | _- _\n"
    	        "  _ -  | |   -_\n"
    	        "      // \\\\\n";
	}
	file.close();
}
