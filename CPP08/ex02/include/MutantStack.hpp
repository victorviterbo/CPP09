/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:55:25 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/18 12:52:11 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template < typename T >
class MutantStack : public std::stack<T> {
	public :
	// CONSTRUCTORS
		MutantStack() {};

		MutantStack(MutantStack &other) {this->c = other.c;};

		MutantStack &operator=(MutantStack &other){
			this->c = other.c;
			return (*this);
		};

	//DESTUCTORS
		~MutantStack() {};
		
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin(){
			return (this->c.begin());
		};

		iterator	end(){
			return (this->c.end());
		};
};