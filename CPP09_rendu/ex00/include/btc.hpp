/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:38:59 by victorviter       #+#    #+#             */
/*   Updated: 2025/11/09 14:21:25 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <iterator>
#include <cstdlib>
#include <map>


std::map<time_t, double>        load_db();
int	input_processing(char *input, std::map<time_t, double> trade);
int	process_line(std::string line, std::map<time_t, double> trade);
int	check_date(std::string date);
int	check_null_value(std::string value);
time_t	date_str_to_timet(std::string date);
std::string	timet_to_date_str(time_t time);