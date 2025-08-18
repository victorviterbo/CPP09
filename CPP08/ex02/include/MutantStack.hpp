

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

template < typename T >
class MutantStack {
	public :
	// CONSTRUCTORS
		MutantStack();
		MutantStack(MutantStack &other);
		MutantStack &operator=(MutantStack &other);
	//DESTUCTORS
		~MutantStack();
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
	private :
		std::stack<T>	_mutstack;
};