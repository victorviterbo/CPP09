/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:54:56 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 14:44:48 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern &other) {
	(void) other;
}

Intern &Intern::operator=(Intern &other) {
	(void) other;
	return (*this);
}

Intern::~Intern() {}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	if (formName == "PresidentialPardonForm")
		return (new PresidentialPardonForm(formTarget));
	else if (formName == "RobotomyRequestForm")
		return (new PresidentialPardonForm(formTarget));
	else if (formName == "ShrubberyCreationForm")
		return (new PresidentialPardonForm(formTarget));
	throw std::invalid_argument("Form Unknown");
}
