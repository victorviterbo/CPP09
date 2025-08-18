/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack copy.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:55:25 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/18 12:36:30 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template < typename T >
class MutantStack : public std::stack<T> {
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
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin();

		iterator	end();
};