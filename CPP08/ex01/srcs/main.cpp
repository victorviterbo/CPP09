/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:01:21 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/30 12:14:08 by vviterbo         ###   ########.fr       */
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
	try
	{
		mynums.addNumber(7);
	}
	catch (std::overflow_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	Span				cont(10);
	int					arr[5] = {4, 6, 1, 2, 4};
	std::vector<int>	v(arr, arr+5);

	cont.addNumber(123);
	std::cout << "New cont = " << std::endl;
	cont.addNumber(0);
	cont.addNumber(-120);
	cont.printValues();
	cont.addNumber(v.begin(), v.end());
	std::cout << "New cont = " << std::endl; 
	cont.printValues();
	std::cout << "longest = " << cont.longestSpan() << std::endl;
	std::cout << "shortest = " << cont.shortestSpan() << std::endl;
	cont.printValues();

	const int			Bigsize = 10000000;
	Span				Bigcont(Bigsize);
	for (double i = 0; i < Bigsize; ++i)
	{
		Bigcont.addNumber(i * (Bigsize - i + 2)/Bigsize);
	}
	std::cout << "longest = " << Bigcont.longestSpan() << std::endl;
	std::cout << "shortest = " << Bigcont.shortestSpan() << std::endl;
}
