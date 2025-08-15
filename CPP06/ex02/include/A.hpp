/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:29:50 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/15 15:20:54 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "Base.hpp"

class A : public Base {
	public :
	// CONSTRUCTORS
		A() {};
		A(A &other) {(void)other; };
		A &operator=(A &other) {(void)other; return (*this);};
	//DESTUCTORS
		~A() {};
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
	private :
};