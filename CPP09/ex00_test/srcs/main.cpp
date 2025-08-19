/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:23:47 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/19 14:51:12 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

int main(int argc, char *argv[])
{
	std::vector<daytrade>	data;

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