/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 19:45:25 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 16:23:44 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	while (argc > 1)
	{
		ScalarConverter::convert(argv[argc - 1]);
		argc--;
	}
	//ScalarConverter::convert("nan");
	//ScalarConverter::convert("18");
}