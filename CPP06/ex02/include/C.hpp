

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "Base.hpp"

class C : public Base  {
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