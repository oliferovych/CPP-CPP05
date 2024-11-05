/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:48:46 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/04 17:20:23 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//Constructors
AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

//Operator "=" overload
AForm &AForm::operator=(const AForm &other)
{
	if(this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

//Deconstructor
AForm::~AForm()
{
}

//Getters
std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (_signed == true)
		throw AlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	else
		_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if(_signed == false)
		throw NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

//Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return "Form has already been signed";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &stream, const AForm &f)
{
	stream << "AForm \"" << f.getName() << "\" is ";
	if (f.getSigned() == true)
		stream << "signed";
	else
		stream << "not signed";
	stream << " and requires a grade " << f.getGradeToSign() << " to sign and a grade " << f.getGradeToExecute() << " to execute";
	return stream;
}
