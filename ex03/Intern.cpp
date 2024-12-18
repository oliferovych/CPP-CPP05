/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:34:35 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/06 16:13:35 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &other)
{
	if (this == &other)
		return *this;
	return *this;
}

AForm *makeShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *makeRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *makePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*functions[3])(std::string) = {makeShrubberyCreationForm, makeRobotomyRequestForm, makePresidentialPardonForm};
	for(int i = 0; name[i]; i++)
		name[i] = std::tolower(name[i]);
	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return functions[i](target);
		}
	}
	std::cerr << "Form " << name << " not found" << std::endl;
	return NULL;
}
