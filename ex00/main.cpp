/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:06:11 by dolifero          #+#    #+#             */
/*   Updated: 2024/10/16 15:28:41 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1("b1", 150);
	Bureaucrat b2("b2", 1);
	Bureaucrat b3("b3", 2);
	Bureaucrat b4("b4", 149);
	Bureaucrat b5("b5", 150);
	Bureaucrat b6("b6", 1);
	Bureaucrat b7("b7", 2);
	Bureaucrat b8("b8", 149);
	Bureaucrat b9("b9", 150);

	try
	{
		b1.incrementGrade();
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << b1 << e.what() << '\n';
	}
	try
	{
		b2.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << b2 << e.what() << '\n';
	}
	try
	{
		b3.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << b3 << e.what() << '\n';
	}
	try
	{
		b4.decrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << b4 << e.what() << '\n';
	}
	std::cout << b1 << b2 << b3 << b4 << b5 << b6 << b7 << b8 << b9;
}
