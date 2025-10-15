/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:05:56 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 22:18:20 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <exception>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
	public :
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const _NOEXCEPT {
					return "Grade is too low! (Must be <= 150)";
				}
		};
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const _NOEXCEPT {
					return "Grade is too high! (Must be >= 1)";
				}
		};

		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat &other);
		Bureaucrat &operator=(Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat	operator++(int);
		Bureaucrat	operator--(int);
	
		std::string const	&getName(void) const;
		unsigned int		getGrade(void) const;

		void				signForm(AForm &form) const;
		void				executeForm(const AForm &form) const;
	private :
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &operand);
