/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:27:09 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/05 17:42:35 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include <ctime>

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		//Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		//Operator "=" overload
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		//Deconstructor
		~PresidentialPardonForm();
		//Getters
		std::string getTarget() const;
		//Methods
		void execute(Bureaucrat const &executor) const;
};

#endif
