/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:42:07 by vviterbo          #+#    #+#             */
/*   Updated: 2025/10/15 17:42:12 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "Base.hpp"

class B : public Base {
	public :
	// CONSTRUCTORS
		B() {};
		B(B &other) {(void)other; };
		B &operator=(B &other) {(void)other; return (*this);};
	//DESTUCTORS
		~B() {};
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
	private :
};
