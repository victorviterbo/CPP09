/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:55:58 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/18 18:35:09 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <iomanip>

int main(int argc, char *argv[])
{
	std::stack<float>	nums;
	std::string			arg;
	float				val1;
	float				val2;

	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments. Exiting ..." << std::endl;
		return (1);
	}
	arg = argv[1];
	for (unsigned int i = 0; i < arg.length(); i++)
	{
		if (std::isspace(arg[i]))
			continue ;
		else if (isdigit(arg[i]))
			nums.push(static_cast<float>(arg[i] - '0'));
		else if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/')
		{
			if (nums.size() < 2)
			{
				std::cout << "Error: invalid syntax" << std::endl;
				return (1);
			}
			val1 = nums.top();
			nums.pop();
			val2 = nums.top();
			nums.pop();
			switch (arg[i])
			{
				case '+':
					nums.push(val2 + val1);
					break ;
				case '*':
					nums.push(val2 * val1);
					break ;
				case '-':
					nums.push(val2 - val1);
					break ;
				case '/':
					nums.push(val2 / val1);
					break ;
			}
		}
	}
	if (nums.size() != 1)
	{
		std::cout << "Error: invalid syntax" << std::endl;
		return (1);
	}
	std::cout << nums.top() << std::endl;
	return (0);
}