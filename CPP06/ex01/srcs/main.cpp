/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:56:18 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/15 13:38:04 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data    *data;

    data = new Data;
    data->age = 12;
    data->Name = "John";
    data->parent = new Data;
    uintptr_t  ptr = Serializer::serialize(data);
    Data    *data2 = Serializer::deserialize(ptr);
    std::cout << data2->Name << " " << data2->age << " " << data2->parent << std::endl;
    return (0);
}