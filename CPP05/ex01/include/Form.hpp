/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:09:57 by victorviter       #+#    #+#             */
/*   Updated: 2025/07/30 22:01:33 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
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
		
		Form();
		Form(std::string name, bool is_signed, unsigned int sign_grade, unsigned int execute_grade);
		Form(Form &other);
		Form &operator=(Form &other);
		~Form();

		void				beSigned(Bureaucrat &GrattePapier);
		
		std::string const	&getName(void) const;
		bool				getSignedStatus(void) const;
		unsigned int		getSignRequirement(void) const;
		unsigned int		getExecuteRequirement(void) const;
	private :
		std::string const	_name;
		bool				_signed;
		unsigned int		_sign_req;
		unsigned int		_execute_req;
};

std::ostream &operator<<(std::ostream &os, const Form &operand);
