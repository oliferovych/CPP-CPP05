/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:20:59 by dolifero          #+#    #+#             */
/*   Updated: 2024/10/16 15:25:21 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade <= 1)
		throw GradeTooHighException();
	if (grade >= 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if(this == &other)
		return *this;
	_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade <= 1)
		throw GradeTooHighException();
	if (grade >= 150)
		throw GradeTooLowException();
	_grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return stream;
}
