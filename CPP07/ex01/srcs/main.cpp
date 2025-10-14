/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:02:37 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 18:04:06 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void plusOne(int &val)
{
	std::cout << "Call to plusOne()" << std::endl;
	val = val + 1;
}

void minusOne(const int &val)
{
	std::cout << "Call to minusOne()" << std::endl;
	std::cout << val - 1 << std::endl;
}

void plusOne(double &val)
{
	std::cout << "Call to plusOne()" << std::endl;
	val = val + 1;
}

void minusOne(const double &val)
{
	std::cout << "Call to minusOne()" << std::endl;
	std::cout << val - 1 << std::endl;
}

int main()
{
	int 	array1[] = {'a', 'b', 'c', 'd'};

	for (int i = 0; i < 4; i++)
		std::cout << "array1[" << i << "]: " << array1[i] << "\n";
	std::cout << "\n" << std::endl;
	
	::iter(array1, 4, plusOne);

	for (int i = 0; i < 4; i++)
		std::cout << "array1[" << i << "]: " << array1[i] << "\n";
	std::cout << "\n" << std::endl;
	
	::iter(array1, 4, minusOne);
	
	for (int i = 0; i < 4; i++)
		std::cout << "array1[" << i << "]: " << array1[i] << "\n";
	std::cout << "\n" << std::endl;
	
	double	array2[] = {1.234, 3, 5.11, 6};
	
	for (int i = 0; i < 4; i++)
		std::cout << "array2[" << i << "]: " << array2[i] << "\n";
	std::cout << "\n" << std::endl;
	
	::iter(array2, 4, plusOne);

	for (int i = 0; i < 4; i++)
		std::cout << "array2[" << i << "]: " << array2[i] << "\n";
	std::cout << "\n" << std::endl;
	
	::iter(array2, 4, minusOne);
	
	for (int i = 0; i < 4; i++)
		std::cout << "array2[" << i << "]: " << array2[i] << "\n";
	std::cout << "\n" << std::endl;
	
	return (0);
}
