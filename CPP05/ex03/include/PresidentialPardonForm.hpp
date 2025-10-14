/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:47:52 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 15:47:54 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm {
	public :
	// CONSTRUCTORS
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(PresidentialPardonForm &other);
	//DESTUCTORS
		~PresidentialPardonForm();
	//GETTERS
		std::string	const &getTarget(void) const;
	//SETTERS
	//MEMBER FUNCTIONS
		void execute(Bureaucrat const &executor) const;
	private :
		std::string		_target;
};