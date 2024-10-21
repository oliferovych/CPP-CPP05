/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:06:11 by dolifero          #+#    #+#             */
/*   Updated: 2024/10/21 15:01:22 by dolifero         ###   ########.fr       */
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

    try {
        b1.decrementGrade();
    } catch(const std::exception &e) {
        std::cerr << e.what() << " " << b1 << '\n';
    }

    try {
        b2.incrementGrade();
    } catch(const std::exception &e) {
        std::cerr << e.what() << " " << b2 << '\n';
    }

    try {
        b3.incrementGrade();
    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    try {
        b4.incrementGrade();
    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    try {
        b5.decrementGrade();
    } catch(const std::exception &e) {
        std::cerr << e.what() << " " << b5 << '\n';
    }

    try {
        b6.incrementGrade();
    } catch(const std::exception &e) {
        std::cerr << e.what() << " " << b6 << '\n';
    }

    try {
        b7.incrementGrade();
    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    try {
        b8.incrementGrade();
    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    try {
        b9.decrementGrade();
    } catch(const std::exception &e) {
        std::cerr << e.what() << " " << b9 << '\n';
    }
	return(0);
}
