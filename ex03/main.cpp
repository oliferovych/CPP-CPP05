/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:06:11 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/06 16:04:58 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Bureaucrat b1("Lazy John", 137);
    Bureaucrat b2("Hardworking John", 45);
    Bureaucrat b3("Nepo Baby", 5);
    Intern bob;
    AForm *f1 = bob.makeForm("shrubbery creation", "home");
    AForm *f2 = bob.makeForm("robotomy request", "Lazy John");
    AForm *f3 = bob.makeForm("presidential pardon", "Lazy John");

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;
    b1.signForm(*f1);
    b1.executeForm(*f1);
    b1.signForm(*f2);
    b2.signForm(*f2);
    b2.executeForm(*f2);
    b3.signForm(*f3);
    b3.executeForm(*f3);
    delete f1;
    delete f2;
    delete f3;
	return(0);
}
