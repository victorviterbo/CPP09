/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:32:03 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 18:32:04 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << numbers.size() << std::endl;
    std::cout << "numbers[123] = " << numbers[123] << std::endl;
    numbers[123] += 1;
    std::cout << "numbers[123] = " << numbers[123] << std::endl;
    numbers[123] -= 1;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] != test[i] || tmp[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        for (int i = 0; i < MAX_VAL; i++)
        {
            tmp[i] = tmp[i] + 1;
        }
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] == test[i] || tmp[i] == numbers[i])
            {
                std::cerr << "copy is not a deep copy" << std::endl;
                return 1;
            }
        }
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
