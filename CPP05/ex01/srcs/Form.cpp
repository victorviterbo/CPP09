/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:49:05 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 22:06:29 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	:	_name("unknown form"),
		_sign_req(1),
		_execute_req(1)
{}

Form::Form(const std::string name, unsigned int sign_grade, unsigned int execute_grade)
	:	_name(name),
		_sign_req(sign_grade),
		_execute_req(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	else if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
	this->_signed = false;
}

Form::Form(Form &other)
	:	_name(other._name),
		_sign_req(other._sign_req),
		_execute_req(other._execute_req)
{
	this->_signed = other._signed;
}

Form &Form::operator=(Form &other)
{
	this->_signed = other._signed;
	return (*this);
}

Form::~Form() {}

void	Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > this->_sign_req)
		throw GradeTooLowException();
	this->_signed = true;
}

std::string const	&Form::getName(void) const
{
	return (this->_name);
}

bool				Form::getSignedStatus(void) const
{
	return (this->_signed);
}

unsigned int		Form::getSignRequirement(void) const
{
	return (this->_sign_req);
}

unsigned int		Form::getExecuteRequirement(void) const
{
	return (this->_execute_req);
}

std::ostream &operator<<(std::ostream &os, const Form &operand)
{
	os << operand.getName() << " is currently signed : " << operand.getSignedStatus() \
	<< "form needs a Bureaucrat of level >= " << operand.getSignRequirement() \
	<< "to be signed and a Bureacrat of level >= " << operand.getExecuteRequirement() \
	<< "to be executed" << std::endl;
	return (os);
}
