

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "Base.hpp"

class B : public Base  {
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