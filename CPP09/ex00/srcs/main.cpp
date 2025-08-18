/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:23:47 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/18 17:52:54 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

int main(int argc, char *argv[])
{
	std::list<daytrade>	data;

	if (argc != 2)
	{
		std::cout << "ERROR : wrong number of arguments. Exiting ..." << std::endl;
		return (1);
	}
	try {
		data = load_db();
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	input_processing(argv[1], data);
	return (0);
}