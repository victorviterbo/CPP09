/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:14:33 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/30 11:51:57 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	int					arr1[] = {1, 2, 4, 6, 8};
	int					arr2[] = {'a', 'b', 'c', 'e', 'f'};
	std::vector<int>	v(arr1, arr1 + 5);
	std::list<int>		l(arr2, arr2 + 5);

		if (easyfind(v, 3) != v.end())
			std::cout << "Value found in container" << std::endl;
		else
			std::cout << "Value not in container" << std::endl;
		if (easyfind(v, 4) != v.end())
			std::cout << "Value found in container" << std::endl;
		else
			std::cout << "Value not in container" << std::endl;
		if (easyfind(l, 'a') != l.end())
			std::cout << "Value found in container" << std::endl;
		else
			std::cout << "Value not in container" << std::endl;
		if (easyfind(l, 'z') != l.end())
			std::cout << "Value found in container" << std::endl;
		else
			std::cout << "Value not in container" << std::endl;
	return (0);
}