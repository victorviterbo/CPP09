/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:01:21 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/16 17:56:22 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	Span    mynums(5);

	mynums.addNumber(3);
	mynums.addNumber(5);
	mynums.addNumber(1);
	mynums.addNumber(13);
	mynums.printValues();
	std::cout << "shortest = " << mynums.shortestSpan() << std::endl;
	mynums.addNumber(7);
	mynums.printValues();
	std::cout << "longest = " << mynums.longestSpan() << std::endl;
	try {
		mynums.addNumber(7);
	}
	catch (std::overflow_error &e){
		std::cerr << e.what() << std::endl;
	}
	//return (0);
	Span				cont(10);
	int					arr[5] = {4, 6, 1, 2, 4};
	std::vector<int>	v(arr, arr+5);

	cont.addNumber(123);
	cont.addNumber(v.begin(), v.end());
	cont.printValues();
	std::cout << "longest = " << cont.longestSpan() << std::endl;
	cont.printValues();
}
