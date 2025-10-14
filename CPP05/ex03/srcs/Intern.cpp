/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:54:56 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 15:52:36 by victorviter      ###   ########.fr       */
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

AForm	*Intern::makePresidentialPardonForm(std::string formTarget)
{
	return (new PresidentialPardonForm(formTarget));
}

AForm	*Intern::makeRobotomyRequestForm(std::string formTarget)
{
	return (new RobotomyRequestForm(formTarget));
}

AForm	*Intern::makeShrubberyCreationForm(std::string formTarget)
{
	return (new ShrubberyCreationForm(formTarget));
}

const int			FormStackSize = 3;
const std::string 	FormNames[FormStackSize] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
AForm				*(*formStack[FormStackSize])(std::string formTarget) = \
				{	&Intern::makePresidentialPardonForm, \
					&Intern::makeRobotomyRequestForm, \
					&Intern::makeShrubberyCreationForm
				};

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{	
	for (unsigned int i = 0; i < FormStackSize; i++)
	{
		if (!FormNames[i].compare(formName))
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formStack[i](formTarget));
		}
	}
	throw std::invalid_argument("Form Unknown");
}
