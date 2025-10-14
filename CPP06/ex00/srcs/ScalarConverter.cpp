/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:50:46 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 16:09:17 by victorviter      ###   ########.fr       */
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
	char	c;
	double	d;
	int		i;
	float	f;

	d = strtod(s.c_str(), &endPtr);
	if (endPtr == s.c_str())
	{
		std::cout << "ERROR could not parse string. Exiting..." << std::endl;
		return ;
	}
	f = static_cast<float>(d);
	if (d == HUGE_VAL || d == -HUGE_VAL)
	{
		std::cout << "char: impossible\nint: impossible\nfloat: " \
		<< f << "\ndouble: " << d << std::endl;
		return ;
	}
	i = static_cast<int>(d);
	if (s[0] == '+' || s[0] == '-' || s[0] == 'n' || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		c = static_cast<char>(d);
		if (std::isprint(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	double intPart;
	if (std::modf(d, &intPart) == 0.0)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << i << "\nfloat: " << f << "f\ndouble: " << d << std::endl;
	return ;
}

void	ScalarConverter::convertChar(std::string s)
{
	char	c;
	double	d;
	int		i;
	float	f;
	
	c = s[0];
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	i = static_cast<int>(c);
	f = static_cast<float>(i);
	d = static_cast<double>(f);
	std::cout << "int: " << i << "\nfloat: " << f << "f\ndouble: " << d << std::endl;
}
