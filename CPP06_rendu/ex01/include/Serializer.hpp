/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:09:36 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/15 12:14:36 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdint.h>

typedef struct Data {
	std::string		Name;
	int				age;
	struct Data		*parent;
}	t_Data;

class Serializer {
	public :
	// CONSTRUCTORS
		Serializer();
		Serializer(Serializer &other);
		virtual Serializer &operator=(Serializer &other);
	//DESTUCTORS
		virtual ~Serializer() = 0;
	//GETTERS
	//SETTERS
	//MEMBER FUNCTIONS
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	private :
};