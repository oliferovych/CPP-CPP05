/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:48:46 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/04 16:25:39 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Constructors
Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

//Operator "=" overload
Form &Form::operator=(const Form &other)
{
	if(this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}

//Deconstructor
Form::~Form()
{
}

//Getters
std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &b)
{
	if (_signed == true)
		throw AlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	else
		_signed = true;
}

//Exceptions
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* Form::AlreadySignedException::what() const throw()
{
	return "Form has already been signed";
}

std::ostream &operator<<(std::ostream &stream, const Form &f)
{
	stream << "Form \"" << f.getName() << "\" is ";
	if (f.getSigned() == true)
		stream << "signed";
	else
		stream << "not signed";
	stream << " and requires a grade " << f.getGradeToSign() << " to sign and a grade " << f.getGradeToExecute() << " to execute";
	return stream;
}
