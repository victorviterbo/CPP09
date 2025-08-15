/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:26:26 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/15 15:15:36 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

class Base {
	public :
	// CONSTRUCTORS
	//DESTUCTORS
		virtual ~Base();
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
		static Base	*generate(void);
		static void	identify(Base* p);
		static void	identify(Base& p);
	private :
};

uint64_t nanosec_seed();