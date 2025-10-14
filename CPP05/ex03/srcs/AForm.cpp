/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:48:04 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 15:48:07 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() {}

AForm::AForm(std::string name, bool is_signed, unsigned int sign_grade, unsigned int execute_grade) : _name(name)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    else if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();
    this->_signed = is_signed;
    this->_sign_req = sign_grade;
    this->_execute_req = execute_grade;
}

AForm::AForm(AForm &other) : _name(other._name)
{
    this->_signed = other._signed;
    this->_sign_req = other._sign_req;
    this->_execute_req = other._execute_req;
}

AForm &AForm::operator=(AForm &other)
{
    this->_signed = other._signed;
    this->_sign_req = other._sign_req;
    this->_execute_req = other._execute_req;
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
