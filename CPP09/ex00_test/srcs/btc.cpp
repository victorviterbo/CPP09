/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:23:47 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/19 14:50:50 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

std::vector<daytrade>	load_db()
{
	std::string				line;
	std::vector<daytrade>	data;
	daytrade				dt;
	std::ifstream 			db;
	const char				*valstr;
	char					*endPtr;

	db.open("data.csv", std::ios::in);
	if(!db)
	{
		throw std::runtime_error("Could not open db");
	}
	while (std::getline(db, line))
	{
		if (line.compare("date,exchange_rate") == 0)
			continue ;
		if (line.length() < 11)
			continue ;
		if (!check_date(line.substr(0, 10)))	
			throw std::runtime_error("DB is not properly formated");
		dt.date = line.substr(0, 10);
		valstr = line.substr(11, line.length()).c_str();
		dt.value = std::strtof(valstr, &endPtr);
		if (valstr == endPtr)
		{
			throw std::runtime_error("Could not parse db");
		}
		data.push_back(dt);
	}
	return (data);
}

int	input_processing(char *input, std::vector<daytrade> data)
{
	std::ifstream 		inputf;
	std::string			line;
	int					ret;

	ret = 0;
	inputf.open(input, std::ios::in);
	if(!inputf)
	{
		std::cout << "Error : could not open input file. Exiting ..." << std::endl;
		return (1);
	}
	while (std::getline(inputf, line))
	{
		if (line.compare("date | value") == 0)
			continue ;
		ret = (process_line(line, data) || ret);
	}
	return (ret);
}

int	process_line(std::string line, std::vector<daytrade> data)
{
	std::string			date;
	float				value;
	const char			*valstr;
	char				*endPtr;

	if (line.length() < 14)
	{
		std::cout << "Error : bad input => " << line << std::endl;
		return (1);
	}
	date = line.substr(0, 10);
	if (!check_date(date))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (1);
	}
	std::vector<daytrade>::iterator it = data.begin();
	std::vector<daytrade>::iterator nextIt = data.begin();
	nextIt++;
	while (it != data.end())
	{
		if ((nextIt != data.end() && date.compare((*nextIt).date) < 0)
			|| (nextIt == data.end() &&  date.compare((*it).date) == 0))
		{
			valstr = line.substr(13, line.length()).c_str();
			value = std::strtof(valstr, &endPtr);
			if (endPtr == valstr)
			{
				std::cout << "Error: value could not be parsed." << std::endl;
				return (1);
			}
			if (value < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				return (1);
			}
			if (value >= INT_MAX)
			{
				std::cout << "Error: too large a number." << std::endl;
				return (1);
			}
			std::cout << date << " => " << value << " = " << value * (*it).value << std::endl;
			return (0);
		}
		++it;
		++nextIt;
	}
	std::cout << "Error: date is in the future." << std::endl;
	return (1);
}

int	check_date(std::string date)
{
	bool	leap;
	int		year;
	int		month;
	int		day;

	if (date.length() != 10)
		return (0);
	if (date[4] != '-' || date[7] != '-')
		return (0);
	year = atoi(date.substr(0, 4).c_str());
	if (year == 0 && (date[0] != 0 || date[1] != 0 || date[2] != 0 || date[3] != 0))
		return (0);
	if (year < 0)
		return (0);
	leap = (year % 400 == 0) || ((year % 4 == 0) && year % 100 != 0);
	month = atoi(date.substr(5, 7).c_str());
	if (month == 0 && (date[5] != 0 || date[6] != 0))
		return (0);
	if (month < 0 || month > 12)
		return (0);
	day = atoi(date.substr(8, 10).c_str());
	if (day == 0 && (date[8] != 0 || date[9] != 0))
		return (0);
	if (day < 0 || day > 31)
		return (0);
	if ((month % 2 == 0 && month < 7) || (month % 2 == 1 && month > 8))
	{
		if (day > 30)
			return (0);
	}
	if (month == 2)
	{
		if ((day > 28 && !leap) || (day > 29 && leap))
			return (0);
	}
	return (1);
}

int	check_null_value(std::string value)
{
	for (unsigned int i = 0; i < value.length(); i++)
	{
		if (value[i] != '0')
			return (0);
	}
	return (1);
}
