/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:02:37 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/28 14:31:04 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void plusOne(int &val)
{
	val = val + 1;
}

void minusOne(const int &val)
{
	std::cout << "Call to minusOne() " << val - 1 << std::endl;
}

void plusOne(double &val)
{
	val = val + 1;
}

void minusOne(const double &val)
{
	std::cout << "Call to minusOne() " << val - 1 << std::endl;
}

int main()
{
	int 	array1[] = {'a', 'b', 'c', 'd'};

	std::cout << "array 1 :" << std::endl;
	::iter(array1, 4, print);
	
	std::cout << "plus 1" << std::endl;
	::iter(array1, 4, plusOne);

	std::cout << "array1" << std::endl;
	::iter(array1, 4, print);
	
	std::cout << "minus 1" << std::endl;
	::iter(array1, 4, minusOne);
	
	std::cout << "array1" << std::endl;
	::iter(array1, 4, print);
	
	double	array2[] = {1.234, 3, 5.11, 6};
	
	std::cout << "array2" << std::endl;
	::iter(array2, 4, print);
	
	std::cout << "plus 1" << std::endl;
	::iter(array2, 4, plusOne);

	std::cout << "array2" << std::endl;
	::iter(array2, 4, print);
	
	std::cout << "minus 1" << std::endl;
	::iter(array2, 4, minusOne);

	std::cout << "array2" << std::endl;
	::iter(array2, 4, print);
	
	return (0);
}
