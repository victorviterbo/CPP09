/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:58:19 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/28 16:54:51 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
/*
template < typename T>
void print(T &elem)
{
	std::cout << elem << std::endl;
}*/

template < typename T>
void	iter(T *array, size_t len, void (*func)(T &))
{
	if (array == NULL || len == 0 || func == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

template < typename T>
void	iter(const T *array, size_t len, void (*func)(const T &))
{
	if (array == NULL || len == 0 || func == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}
