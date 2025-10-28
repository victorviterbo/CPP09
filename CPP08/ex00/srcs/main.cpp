/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:14:33 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/28 15:43:19 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	int					arr1[] = {1, 2, 4, 6, 8};
	int					arr2[] = {'a', 'b', 'c', 'e', 'f'};
	std::vector<int>	v(arr1, arr1 + 5);
	std::list<int>		l(arr2, arr2 + 5);

	try {
		easyfind(v, 3);
		std::cout << "Value found in container" << std::endl;
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(v, 4);
		std::cout << "Value found in container" << std::endl;
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(l, 'a');
		std::cout << "Value found in container" << std::endl;
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(l, 'z');
		std::cout << "Value found in container" << std::endl;
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}