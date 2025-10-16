/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:50:46 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/16 12:37:07 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

void		ScalarConverter::convert(std::string s) 
{
	if (s.length() == 0)
		std::cout << "Cannot convert the string" << std::endl;
	else if ((s == "inff" || s == "+inff" || s == "-inff" || s == "nanf"
		|| (s.find(".") != std::string::npos && s[0] != '.'))
		&& s[s.size() - 1] == 'f')
		convertFloat(s);
	else if ((s == "inf" || s == "+inf" || s == "-inf" || s == "nan")
		|| (s.find(".") != std::string::npos && s[0] != '.'))
		convertDouble(s);
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

	d = strtod(s.c_str(), &endPtr);
	if (errno == ERANGE || *endPtr != '\0')
	{
		std::cout << "ERROR could not parse string double. Exiting..." << std::endl;
		return ;
	}
	if (s == "nan" || std::isnan(d))
	{
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
		return ;
	}
	if (trunc(d) == d && std::numeric_limits<int>::min() < d && d < std::numeric_limits<int>::max())
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
	if (std::numeric_limits<float>::min() < d && d < std::numeric_limits<float>::max())
	{
		f = static_cast<float>(d);
		if (trunc(f) == f)
			std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
	}
	else if (d == HUGE_VAL)
		std::cout << "float: inff" << std::endl;
	else if (d == -HUGE_VAL)
		std::cout << "float: -inff" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	if (trunc(d) == d)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
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
	if (errno == ERANGE || *endPtr != '\0')
	{
		std::cout << "ERROR could not parse string float. Exiting..." << std::endl;
		return ;
	}
	if (s == "nanf" || std::isnan(f))
	{
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
		return ;
	}
	if (trunc(f) == f && std::numeric_limits<int>::min() < f && f < std::numeric_limits<int>::max())
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
	char	c;
	double	d;
	int		i;
	float	f;
	long	l;
	char	*endPtr;
	
	l = strtol(s.c_str(), &endPtr, 10);
	if (errno == ERANGE || *endPtr != '\0')
	{
		std::cout << "ERROR could not parse string int. Exiting..." << std::endl;
		return ;
	}
	if (l == 0)
	{
		unsigned int it = 0;
		if (s[0] == '+' || s[0] == '-')
			it = 1;
		for (; it < s.length(); ++it)
		{
			if (s[it] != 0)
			{
				std::cout << "Cannot convert the string" << std::endl;
				return ;
			}
		}
	}
	if (std::numeric_limits<int>::max() <= l || l <= std::numeric_limits<int>::min())
	{
		std::cout << "char: impossible\nint: impossible" << std::endl;
	}
	else
	{
		i = static_cast<int>(l);
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
	std::cout << std::fixed << std::setprecision(1);
	if (std::numeric_limits<float>::min() < l && l < std::numeric_limits<float>::max())
	{
		f = static_cast<float>(l);
		std::cout << "float: " << f << "f" << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
	d = static_cast<double>(l);
	std::cout << "double: " << d << std::endl;
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
