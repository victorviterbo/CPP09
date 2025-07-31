/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:05:56 by victorviter       #+#    #+#             */
/*   Updated: 2025/07/31 22:16:09 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <exception>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
	public :
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const _NOEXCEPT {
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const _NOEXCEPT {
					return "Grade is too low";
				}
		};
		Bureaucrat();
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat &other);
		Bureaucrat &operator=(Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat	operator++(int);
		Bureaucrat	operator--(int);
	
		std::string const	&getName(void) const;
		unsigned int		getGrade(void) const;

		void    			signForm(AForm &form);
		void   				executeForm(AForm const &form);
	private :
		std::string		_name;
		unsigned int	_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &operand);

#include <time.h>
#include <stdint.h>