/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:39:19 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 15:46:36 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	:	_name("unknown form"),
		_sign_req(1),
		_execute_req(1)
{}
AForm::AForm(std::string name, const unsigned int sign_grade, const unsigned int execute_grade) : _name(name), _sign_req(sign_grade), _execute_req(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	else if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
	this->_signed = false;
}

AForm::AForm(AForm &other) : _name(other._name), _sign_req(other._sign_req), _execute_req(other._execute_req)
{
}

AForm &AForm::operator=(AForm &other)
{
	if (this != &other)
	this->_signed = other._signed;
	return (*this);
}

AForm::~AForm() {}

void	AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > this->_sign_req)
		throw GradeTooLowException();
	this->_signed = true;
}

std::string const	&AForm::getName(void) const
{
	return (this->_name);
}

bool				AForm::getSignedStatus(void) const
{
	return (this->_signed);
}

unsigned int		AForm::getSignRequirement(void) const
{
	return (this->_sign_req);
}

unsigned int		AForm::getExecuteRequirement(void) const
{
	return (this->_execute_req);
}

std::ostream &operator<<(std::ostream &os, const AForm &operand)
{
	os << operand.getName() << " is currently signed : " << operand.getSignedStatus() \
	<< "AForm needs a Bureaucrat of level >= " << operand.getSignRequirement() \
	<< "to be signed and a Bureacrat of level >= " << operand.getExecuteRequirement() \
	<< "to be executed" << std::endl;
	return (os);
}
