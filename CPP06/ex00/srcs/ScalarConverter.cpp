/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:50:46 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/02 20:22:04 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

void		ScalarConverter::convert(std::string s) 
{
	if (((s[0] == '+' || s[0] == '-' || s[0] == 'n') && s.length() > 1)
		|| isdigit(s[0]))
		convertNumber(s);
	else if (s.length() == 1)
		convertChar(s);
};

void	ScalarConverter::convertNumber(std::string s)
{
	char	*endPtr;

	double i = strtod(s.c_str(), &endPtr);
	std::cout << "char: ";
	if (s[0] == '+' || s[0] == '-' || s[0] == 'n'){
		std::cout << "impossible" << std::endl;
	}
	else 
		std::cout << i << std::endl;
}

void	ScalarConverter::convertChar(std::string s)
{
	(void)s;
}
