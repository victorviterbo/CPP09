/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:20:45 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/01 14:29:47 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat  A("Victor", 12);
	Intern		sbire;
	AForm		*forms[9];

	for (int i = 0; i < 3; i++)
		forms[i] = sbire.makeForm("PresidentialPardonForm", "form_" + std::to_string(i) + "C.docx");
	for (int i = 3; i < 6; i++)
		forms[i] = sbire.makeForm("RobotomyRequestForm", "form_" + std::to_string(i) + "C.docx");
	for (int i = 6; i < 9; i++)
		forms[i] = sbire.makeForm("ShrubberyCreationForm", "form_" + std::to_string(i) + "C.docx");
	for (int i = 0; i < 9; i++)
	{
		try {
			A.signForm(*forms[i]);
		}
		catch (AForm::GradeTooLowException &error){
			std::cerr << "Error: " << error.what() << std::endl;
		}
	}
	for (int i = 0; i < 9; i++)
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
