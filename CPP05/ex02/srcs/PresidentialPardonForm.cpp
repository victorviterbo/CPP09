/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 08:55:12 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 15:48:50 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : AForm(other)
{
	this->_target = other.getTarget();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	this->_target = other.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string const	&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getExecuteRequirement() < executor.getGrade())
		throw GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
