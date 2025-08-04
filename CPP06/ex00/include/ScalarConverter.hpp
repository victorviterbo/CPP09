/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:50:29 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/02 20:07:11 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

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
		static void	convert(std::string x);
		static void	convertNumber(std::string);
		static void	convertChar(std::string);
	private :
};
