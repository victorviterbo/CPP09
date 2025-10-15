/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:48:34 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 22:32:38 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int		seed()
{
	struct timespec t;
	clock_gettime(CLOCK_REALTIME, &t);
	return (t.tv_nsec);
}

RobotomyRequestForm::RobotomyRequestForm()
{
	srand(seed());
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : \
AForm("RobotomyRequestForm", false, 72, 45)
{
	this->_target = target;
	srand(seed());
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) : \
AForm(other.getName(), other.getSignedStatus(), other.getSignRequirement(), other.getExecuteRequirement())
{
	this->_target = other.getTarget();
	srand(seed());
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	this->_target = other.getTarget();
	srand(seed());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string const	&RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getExecuteRequirement() < executor.getGrade())
		throw GradeTooLowException();
	std::cout << "* BZZZZZ BRRRRR BZZZZZZ * (drilling noises)" << std::endl;
	int n = rand() % 10;
	if (n >= 5)
		std::cout << "Robotomy on " << this->_target << " was successful" << std::endl;
	else
		std::cout << "Oops... Robotomy on " << this->_target << " was butchered" << std::endl;
}
