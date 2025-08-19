/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:38:59 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/19 14:51:47 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include <iterator>
#include <cstdlib>
#include <vector>

typedef struct d_daytrade {
        std::string     date;
        float           value;
}   daytrade;

std::vector<daytrade>	load_db();
int	input_processing(char *input, std::vector<daytrade> data);
int	process_line(std::string line, std::vector<daytrade> data);
int	check_date(std::string date);
int	check_null_value(std::string value);