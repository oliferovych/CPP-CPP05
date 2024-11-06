/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:06:11 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/05 18:33:04 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat b1("Lazy John", 137);
    Bureaucrat b2("Hardworking John", 45);
    Bureaucrat b3("Nepo Baby", 5);
    ShrubberyCreationForm f1("home");
    RobotomyRequestForm f2("Lazy John");
    PresidentialPardonForm f3("Lazy John");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    b1.signForm(f1);
    b1.executeForm(f1);
    b1.signForm(f2);
    b2.signForm(f2);
    b2.executeForm(f2);
    b3.signForm(f3);
    b3.executeForm(f3);
	return(0);
}
