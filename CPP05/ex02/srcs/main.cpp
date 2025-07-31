/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:20:45 by victorviter       #+#    #+#             */
/*   Updated: 2025/07/31 22:28:18 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat  A("Victor", 12);
	Bureaucrat  B("Gratte Papier en Chef", 25);	
	AForm		*forms[9];

	for (int i = 0; i < 3; i++)
		forms[i] = new PresidentialPardonForm("some form");
	for (int i = 3; i < 6; i++)
		forms[i] = new RobotomyRequestForm("some form");
	for (int i = 6; i < 9; i++)
		forms[i] = new ShrubberyCreationForm("some form");
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
