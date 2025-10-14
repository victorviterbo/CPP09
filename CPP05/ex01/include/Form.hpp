/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:09:57 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 15:40:09 by victorviter      ###   ########.fr       */
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
		Form(std::string name, unsigned int sign_grade, unsigned int execute_grade);
		Form(Form &other);
		Form &operator=(Form &other);
		~Form();

		void				beSigned(const Bureaucrat &signer);
		
		std::string const	&getName(void) const;
		bool				getSignedStatus(void) const;
		unsigned int		getSignRequirement(void) const;
		unsigned int		getExecuteRequirement(void) const;
	private :
		const std::string	_name;
		bool				_signed;
		const unsigned int	_sign_req;
		const unsigned int	_execute_req;
};

std::ostream &operator<<(std::ostream &os, const Form &operand);
