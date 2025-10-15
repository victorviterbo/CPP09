/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:50:39 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 15:10:34 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm {
	public :
	// CONSTRUCTORS
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm &other);
	//DESTUCTORS
		~RobotomyRequestForm();
	//GETTERS
		std::string	const &getTarget(void) const;
	//SETTERS
	//MEMBER FUNCTIONS
		void execute(Bureaucrat const &executor) const;
	private :
		std::string			_target;
};