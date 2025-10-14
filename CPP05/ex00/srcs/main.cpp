/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:20:45 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 13:23:42 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat  A("Victor", 12);
    std::cout << A << std::endl;
    std::cout << A.getName() << std::endl;
    std::cout << A.getGrade() << std::endl;
    try
    {
        Bureaucrat  B("Luc", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
    }
    try
    {
        Bureaucrat  C("Etienne", 151);;
    }
    catch (const Bureaucrat::GradeTooLowException& error)
    {
        std::cerr << "Error: " << error.what() << std::endl;
    }
    A++;
    std::cout << A.getGrade() << std::endl;
    A--;
    A--;
    A--;
    A--;
    A--;
    std::cout << A.getGrade() << std::endl;
    return (0);
}