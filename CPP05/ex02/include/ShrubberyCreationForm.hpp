/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:48:56 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 21:34:10 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : virtual public AForm {
	public :
	// CONSTRUCTORS
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);
	//DESTUCTORS
		~ShrubberyCreationForm();
	//GETTERS
		std::string	const &getTarget(void) const;
	//SETTERS
	//MEMBER FUNCTIONS
		void execute(Bureaucrat const &executor) const;
	private :
		std::string					_target;
		static const std::string	tree_str;
};

