/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:20:45 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 16:32:48 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

inline std::string intToString(int integer)
{
    std::stringstream	stream;
    stream << integer;
    return stream.str();
}

int main(void)
{
	Bureaucrat	A("Victor", 12);
	Intern		sbire;
	AForm		*forms[9];

	for (int i = 0; i < 3; i++)
		forms[i] = sbire.makeForm("PresidentialPardonForm", "Form_" + intToString(i) + "C.docx");
	for (int i = 3; i < 6; i++)
		forms[i] = sbire.makeForm("RobotomyRequestForm", "Form_" + intToString(i) + "C.docx");
	for (int i = 6; i < 9; i++)
		forms[i] = sbire.makeForm("ShrubberyCreationForm", "Form_" + intToString(i) + "C.docx");
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
