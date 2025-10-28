/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:20:45 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 15:37:32 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat	A("Victor", 12);
	Bureaucrat	B("Gratte Papier en Chef", 25);
	
	Form		Doc1("Very Important Document", 8, 2);
	Form		Doc2("Another Important Document", 21, 1);
	
	A.signForm(Doc1);
	A.signForm(Doc2);
	B.signForm(Doc1);
	B.signForm(Doc2);

	try {
		Form	Doc10("Probably rubish", 1000, 2);
	}
	catch (const Bureaucrat::GradeTooLowException &error) {
		std::cerr << "Bureaucrat Error: " << error.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}
	
	try {
		Form	Doc11("Certainly rubish", 10, 200);
	}
	catch (const Form::GradeTooLowException &error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}
	
	try {
		Form	Doc12("Looks like important rubish", 0, 200);
	}
	catch (const Form::GradeTooHighException &error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}
	
	try {
		Form	Doc13("To hell with it", 100, 0);
	}
	catch (const Form::GradeTooHighException &error) {
		std::cerr << "Error: " << error.what() << std::endl;
	}
	return (0);
}