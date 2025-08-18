/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:38:59 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/18 17:51:37 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <iostream>
#include <fstream>
#include <list>
#include <limits>
#include <string>

typedef struct d_daytrade {
        std::string     date;
        float           value;
}   daytrade;

std::list<daytrade>	load_db();
int	input_processing(char *input, std::list<daytrade> data);
int	process_line(std::string line, std::list<daytrade> data);
int	check_date(std::string date);
int	check_null_value(std::string value);