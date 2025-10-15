/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:05:56 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 15:05:59 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat {
	public :
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too low! (Must be <= 150)";
				}
		};
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
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

		void				signForm(Form &form) const;
	private :
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &operand);
