/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:54:56 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 14:50:48 by victorviter      ###   ########.fr       */
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

static AForm	*makePresidentialPardonForm(std::string formTarget)
{
	return (new PresidentialPardonForm(formTarget));
}

static AForm	*makeRobotomyRequestForm(std::string formTarget)
{
	return (new RobotomyRequestForm(formTarget));
}

static AForm	*makeShrubberyCreationForm(std::string formTarget)
{
	return (new ShrubberyCreationForm(formTarget));
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	const int       FormStackSize = 3;
	std::string 	names[FormStackSize] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm            *(*formStack[FormStackSize])(std::string formTarget) = \
						{&makePresidentialPardonForm, \
						 &makeRobotomyRequestForm, \
						 &makeShrubberyCreationForm};
	
	for (unsigned int i = 0; i < FormStackSize; i++)
	{
		if (!names[i].compare(formName))
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formStack[i](formTarget));
		}
	}
	throw std::invalid_argument("Form Unknown");
}
