/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:59 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/09 13:50:27 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils.hpp"

template < typename T >
void		recursiveMergeInsert(T &main, T &mixed, unsigned int level);

template < typename T >
void		blockSort(T &mixed, unsigned int level);

template < typename T >
void		mergeInMain(T &main, T &predecessors);

template < typename T >
size_t		insertIntoMain(T &main, int n, size_t indx);

#include "FordJohnson.tpp"