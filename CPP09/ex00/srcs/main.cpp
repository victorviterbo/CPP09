/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:23:47 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/29 11:12:50 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

int main(int argc, char *argv[])
{
	std::map<time_t, double>	trade;

	if (argc != 2)
	{
		std::cout << "ERROR : wrong number of arguments. Exiting ..." << std::endl;
		return (1);
	}
	try {
		trade = load_db();
	}
	catch (std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	input_processing(argv[1], trade);
	return (0);
}