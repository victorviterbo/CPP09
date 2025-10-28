/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:42:24 by vviterbo          #+#    #+#             */
/*   Updated: 2025/10/15 17:45:34 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "Base.hpp"

class C : public Base {
	public :
	// CONSTRUCTORS
		C() {};
		C(C &other) {(void)other; };
		C &operator=(C &other) {(void)other; return (*this);};
	//DESTUCTORS
		~C() {};
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
	private :
};
