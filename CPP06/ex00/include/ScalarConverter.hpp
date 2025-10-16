/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:50:29 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/16 12:18:49 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <climits>
#include <limits>
#include <cerrno>

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
