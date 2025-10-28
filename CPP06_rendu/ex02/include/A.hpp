/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:29:50 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 17:43:53 by vviterbo         ###   ########.fr       */
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