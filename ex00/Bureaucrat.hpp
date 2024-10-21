/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:06:39 by dolifero          #+#    #+#             */
/*   Updated: 2024/10/21 14:51:59 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
		void setGrade(int grade);
	public:
	//Constructros
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &other);
	//Operator "=" overload
		Bureaucrat &operator=(const Bureaucrat &other);
	//Deconstructor
		~Bureaucrat();
	//Getters
		std::string getName() const;
		int getGrade() const;
	//Methods
		void incrementGrade();
		void decrementGrade();
	//Exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &b);

#endif
