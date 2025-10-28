/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:56:18 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/15 17:41:19 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data	*data;

	data = new Data;
	data->age = 12;
	data->Name = "John";
	data->parent = new Data;

	uintptr_t	ptr = Serializer::serialize(data);
	Data		*data2 = Serializer::deserialize(ptr);

	std::cout << "old ptr = " << data << "\nnew ptr = " << data2 << std::endl;
	std::cout << data2->Name << " " << data2->age << " " << data2->parent << std::endl;
	return (0);
}