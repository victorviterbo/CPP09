/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:50:29 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 17:07:40 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <climits>

class ScalarConverter {
	public :
	// CONSTRUCTORS
		ScalarConverter();
		ScalarConverter(ScalarConverter &other);
		ScalarConverter &operator=(ScalarConverter &other);
	//DESTUCTORS
		virtual ~ScalarConverter() = 0;
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
		static void	convert(std::string s);
		static void	convertDouble(std::string s);
		static void	convertFloat(std::string s);
		static void	convertInt(std::string s);
		static void	convertChar(std::string s);
	private :
};
