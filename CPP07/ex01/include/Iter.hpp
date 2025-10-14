/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:58:19 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 18:03:01 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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
