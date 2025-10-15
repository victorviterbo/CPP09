/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:50:46 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 19:32:18 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

void		ScalarConverter::convert(std::string s) 
{
	if ((s == "inf" || s == "+inf" || s == "-inf" || s == "nan")
		|| (s.find(".") != std::string::npos && s[0] != '.'))
	{
		if (s[s.size() - 1] == 'f')
			convertFloat(s);
		else
			convertDouble(s);
	}
	else if (std::isdigit(s[0])
		|| ((s[0] == '+' || s[0] == '-') && s.length() > 1))
		convertInt(s);
	else if (s.length() == 1)
		convertChar(s);
	else
		std::cout << "Cannot convert the string" << std::endl;
};

void	ScalarConverter::convertDouble(std::string s)
{
	char	*endPtr;
	char	c;
	double	d;
	int		i;
	float	f;

	if (s[0] == '+')
		s.erase(0, 1);
	d = strtod(s.c_str(), &endPtr);
	if (*endPtr != '\0')
	{
		std::cout << "ERROR could not parse string double. Exiting..." << std::endl;
		return ;
	}
	if (s == "nan" || std::isnan(d))
	{
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
		return ;
	}
	if (trunc(d) == d && INT_MIN < d && d < INT_MAX)
	{
		i = static_cast<int>(d);
		if (i < 0 || i > 127)
			std::cout << "char: impossible\n";
		else
		{
			c = static_cast<char>(i);
			if (std::isprint(c))
				std::cout << "char: " << c << "\n";
			else
				std::cout << "char: Non displayable\n";
		}
		std::cout << "int: " << i << std::endl;
	}
	else
		std::cout << "char: impossible\nint: impossible" << std::endl;
	f = static_cast<float>(d);
	if (d == HUGE_VAL || d == -HUGE_VAL)
	{
		std::cout << "char: impossible\nint: impossible\nfloat: " \
		<< f << "\ndouble: " << d << std::endl;
		return ;
	}
	if (trunc(d) == d)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\ndouble: " << d << std::endl;
	return ;
}

void	ScalarConverter::convertFloat(std::string s)
{
	char	*endPtr;
	char	c;
	double	d;
	int		i;
	float	f;

	if (s[0] == '+')
		s.erase(0, 1);
	if (s[s.size() - 1] == 'f')
		s.erase(s.size() - 1, 1);
	f = strtof(s.c_str(), &endPtr);
	if (*endPtr != '\0')
	{
		std::cout << "ERROR could not parse string float. Exiting..." << std::endl;
		return ;
	}
	if (s == "nanf" || std::isnan(f))
	{
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
		return ;
	}
	if (trunc(f) == f && static_cast<float>(INT_MIN) < f && f < static_cast<float>(INT_MAX))
	{
		i = static_cast<int>(f);
		if (i < 0 || i > 127)
			std::cout << "char: impossible\n";
		else
		{
			c = static_cast<char>(i);
			if (std::isprint(c))
				std::cout << "char: " << c << "\n";
			else
				std::cout << "char: Non displayable\n";
		}
		std::cout << "int: " << i << std::endl;
	}
	else
		std::cout << "char: impossible\nint: impossible" << std::endl;
	if (trunc(f) == f)
		std::cout << std::fixed << std::setprecision(1);
	d = static_cast<double>(f);
	std::cout << "float: " << f << "f\ndouble: " << d << std::endl;
}

void	ScalarConverter::convertInt(std::string s)
{
	//size_t	endPos;
	char	c;
	double	d;
	int		i;
	float	f;
	
	i = atoi(s.c_str());
	/*endPos = 1;
	if (endPos != s.length())
	{
		std::cout << "ERROR could not parse string int . Exiting..." << std::endl;
		return ;
	}*/
	if (i < 0 || i > 127)
	{
		std::cout << "char: impossible\n";
		std::cout << std::fixed << std::setprecision(1);
	}
	else
	{
		c = static_cast<char>(i);
		if (std::isprint(c))
			std::cout << "char: " << c << "\n";
		else
			std::cout << "char: Non displayable\n";
	}
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	std::cout << "int: " << i << std::endl;
	if (trunc(f) == f)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\ndouble: " << d << std::endl;
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
	else
		std::cout << "char: Non displayable" << std::endl;
	i = static_cast<int>(c);
	f = static_cast<float>(i);
	d = static_cast<double>(f);
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\ndouble: " << d << std::endl;
}
