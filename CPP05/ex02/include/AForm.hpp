/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:48:45 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 19:18:35 by vviterbo         ###   ########.fr       */
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
				const char* what() const throw() {
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too low";
				}
		};
		
		class UnsignedFormException : public std::exception {
			public:
				const char* what() const throw() {
					return "Form is not signed";
				}
		};

		AForm();
		AForm(std::string name, const unsigned int sign_grade, const unsigned int execute_grade);
		AForm(AForm &other);
		virtual AForm &operator=(AForm &other);
		virtual ~AForm() = 0;

		virtual void 		execute(Bureaucrat const &executor) const = 0;

		void				beSigned(const Bureaucrat &signer);
		
		std::string const	&getName(void) const;
		bool				getSignedStatus(void) const;
		unsigned int		getSignRequirement(void) const;
		unsigned int		getExecuteRequirement(void) const;
	private :
		std::string const		_name;
		bool					_signed;
		const unsigned int		_sign_req;
		const unsigned int		_execute_req;
};

std::ostream &operator<<(std::ostream &os, const AForm &operand);
