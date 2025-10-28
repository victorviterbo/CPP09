/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:32:03 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/28 17:02:31 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

int main(int, char**)
{
	Array<int> zero_sized(0);
	std::cout << "zero_sized.size = " << zero_sized.size() << std::endl;

	const int arr_size = 200;
	Array<int> numbers(arr_size);
	for (int i = 0; i < arr_size; i++)
		numbers[i] = i;

	const Array<int> arr_copy(numbers);

	std::cout << "number size = " << numbers.size() << ", arr_copy size = " << numbers.size() << std::endl;
	std::cout << "numbers[123] = " << numbers[123] << ", arr_copy[123] = " << arr_copy[123] << std::endl;
	numbers[123] += 1;
	std::cout << "numbers[123] = " << numbers[123] << ", arr_copy[123] = " << arr_copy[123] << std::endl;
	{
		Array<int> arr_copy2 = numbers;
		Array<int> arr_equal = numbers;
		for (int i = 0; i < arr_size; i++)
		{
			if (numbers[i] != arr_copy2[i] || numbers[i] != arr_equal[i])
			{
				std::cout << "Copy constructor failed !" << std::endl;
				return 1;
			}
		}
		for (int i = 0; i < arr_size; i++)
		{
			numbers[i] = numbers[i] + 1;
		}
		for (int i = 0; i < arr_size; i++)
		{
			if (numbers[i] == arr_copy2[i])
			{
				std::cout << "copy is not a deep copy" << std::endl;
				return 1;
			}
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Accessing -2: " << e.what() << std::endl;
	}
	try
	{
		numbers[arr_size] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Accessing arr_size: " << e.what() << std::endl;
	}
	return 0;
}
