/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:06:11 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/05 18:04:40 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    Bureaucrat b1("Lazy John", 137);
    ShrubberyCreationForm f1("home");

    std::cout << b1 << std::endl;
    // b1.signForm(f1);
    b1.executeForm(f1);
	return(0);
}
