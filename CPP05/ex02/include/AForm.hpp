/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:48:45 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 13:40:59 by victorviter      ###   ########.fr       */
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

class AForm {
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
		
		AForm();
		AForm(std::string name, bool is_signed, unsigned int sign_grade, unsigned int execute_grade);
		AForm(AForm &other);
		virtual AForm &operator=(AForm &other);
		virtual ~AForm() = 0;

		virtual void 		execute(Bureaucrat const &executor) const = 0;

		void				beSigned(Bureaucrat &signer);
		
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

std::ostream &operator<<(std::ostream &os, const AForm &operand);
