/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:55:18 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/18 12:39:32 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template < typename T >
MutantStack<T>::MutantStack() {}

template < typename T >
MutantStack<T>::MutantStack(MutantStack &other)
{
	this->c = other.c;
}

template < typename T >
MutantStack<T> &MutantStack<T>::operator=(MutantStack &other)
{
	this->c = other.c;
	return (*this);
};

template < typename T >
MutantStack<T>::~MutantStack() {}


template < typename T >
iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template < typename T >
iterator	MutantStack<T>::end()
{
	return (this->c.end());
}