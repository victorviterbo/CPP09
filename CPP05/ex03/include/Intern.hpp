/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:47:40 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 15:51:40 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public :
	// CONSTRUCTORS
		Intern();
		Intern(Intern &other);
		Intern &operator=(Intern &other);
	//DESTUCTORS
		~Intern();
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
		AForm			*makeForm(std::string formName, std::string formTarget);
		static AForm	*makePresidentialPardonForm(std::string formTarget);
		static AForm	*makeRobotomyRequestForm(std::string formTarget);
		static AForm	*makeShrubberyCreationForm(std::string formTarget);
	private :
};

