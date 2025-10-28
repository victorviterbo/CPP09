/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:20:45 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 15:00:56 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <stdio.h>
#include <stdlib.h>

inline std::string intToString(int integer)
{
    std::stringstream	stream;
    stream << integer;
    return stream.str();
}


int main(void)
{
	Bureaucrat	A("Boss", 2);
	Bureaucrat	B("Victor", 12);
	Bureaucrat	C("Gratte Papier en Chef", 25);	
	AForm		*forms[9];

	for (int i = 0; i < 3; i++)
		forms[i] = new PresidentialPardonForm("Form_" + intToString(i) + "C.docx");
	for (int i = 3; i < 6; i++)
		forms[i] = new RobotomyRequestForm("Form_" + intToString(i) + "C.docx");
	for (int i = 6; i < 9; i++)
		forms[i] = new ShrubberyCreationForm("Form_" + intToString(i) + "C.docx");
	for (int i = 0; i < 9; i++)
	{
		try {
			B.signForm(*forms[i]);
		}
		catch (AForm::GradeTooLowException &error){
			std::cerr << "Error: " << error.what() << std::endl;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		try {
			C.executeForm(*forms[i]);
		}
		catch (AForm::GradeTooLowException &error){
			std::cerr << "Error: " << error.what() << std::endl;
		}
	}
	for (int i = 3; i < 6; i++)
	{
		try {
			A.executeForm(*forms[i]);
			A.executeForm(*forms[i]);
			A.executeForm(*forms[i]);
			A.executeForm(*forms[i]);
			A.executeForm(*forms[i]);
			A.executeForm(*forms[i]);
			A.executeForm(*forms[i]);
		}
		catch (AForm::GradeTooLowException &error){
			std::cerr << "Error: " << error.what() << std::endl;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		try {
			A.executeForm(*forms[i]);
		}
		catch (AForm::GradeTooLowException &error){
			std::cerr << "Error: " << error.what() << std::endl;
		}
	}
	for (int i = 0; i < 9; i++)
		delete forms[i];
	return (0);
}
