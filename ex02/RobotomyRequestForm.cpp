/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:33:08 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/05 18:25:25 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 137), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	if(this == &other)
		return;
	_target = other._target;
}

//Operator "=" overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if(this == &other)
		return *this;
	AForm::operator=(other);
	_target = other._target;
	return *this;
}

//Deconstructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

//Getters
std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

//Methods
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "Bzzzzzzzz" << std::endl;
	srand(time(NULL));
	bool success = rand() % 2;
	if(success)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy has failed." << std::endl;
}
