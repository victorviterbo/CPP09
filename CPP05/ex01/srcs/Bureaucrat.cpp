/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:05:43 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 14:49:01 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &other)
{
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	Bureaucrat::operator++(int)
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade -= 1;
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int)
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::signForm(Form &form) const
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e){
		std::cout << this->getName() << " couldn't sign " << form.getName() << \
		", because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &operand)
{
	os << operand.getName() << ", bureaucrat grade " << operand.getGrade();
	return (os);
}
