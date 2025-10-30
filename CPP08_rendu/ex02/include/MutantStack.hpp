/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:55:25 by vviterbo          #+#    #+#             */
/*   Updated: 2025/10/29 10:44:11 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template < typename T >
class MutantStack : public std::stack<T> {
	public :
	// CONSTRUCTORS
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
	//DESTUCTORS
		~MutantStack();
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"