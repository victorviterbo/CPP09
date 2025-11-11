/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:23:47 by victorviter       #+#    #+#             */
/*   Updated: 2025/11/09 15:49:54 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

std::map<time_t, double>	load_db()
{
	std::ifstream 				db;
	std::string					line;
	std::map<time_t, double>	trade;
	std::string					date;
	time_t						date_t;
	float						value;
	const char					*valstr;
	char						*endPtr;

	db.open("data.csv", std::ios::in);
	if(!db)
	{
		throw std::runtime_error("Could not open db");
	}
	while (std::getline(db, line))
	{
		if (line.compare("date,exchange_rate") == 0)
			continue ;
		if (line.length() < 10)
			continue ;
		date = line.substr(0, 10);
		date_t = date_str_to_timet(date);
		valstr = line.substr(11, line.length()).c_str();
		value = std::strtod(valstr, &endPtr);
		if (*endPtr != '\0')
		{
			throw std::runtime_error("Could not parse db");
		}
		trade[date_t] = value;
	}
	return (trade);
}

int	input_processing(char *input, std::map<time_t, double> trade)
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
		ret = (process_line(line, trade) || ret);
	}
	return (ret);
}

int	process_line(std::string line, std::map<time_t, double> trade)
{
	time_t				date_t;
	float				value;
	const char			*valstr;
	char				*endPtr;

	if (line.length() < 14)
	{
		std::cout << "Error : bad input => " << line << std::endl;
		return (1);
	}
	if (!check_date(line.substr(0, 10)))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (1);
	}
	valstr = line.substr(13, line.length()).c_str();
	value = std::strtof(valstr, &endPtr);
	if (*endPtr != '\0')
	{
		std::cout << "last char parsed = >" << *endPtr << "<" << std::endl;
		std::cout << "Error: value could not be parsed." << std::endl;
		return (1);
	}
	if (value <= 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	if (value >= 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (1);
	}
	date_t = date_str_to_timet(line.substr(0, 10));
	std::map<time_t, double>::iterator it = trade.upper_bound(date_t);
	if (it == trade.begin())
	{
		std::cout << "Error: date is too far in the past." << std::endl;
		return (1);
	}
	--it;
	std::cout << timet_to_date_str(date_t) << " => " << value << " = " << value * it->second << std::endl;
	return (0);
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

time_t	date_str_to_timet(std::string date)
{
	struct tm 		time_struct;
	time_t			time;
	
	if (date.length() < 10)
		return (0);
	if (!check_date(date))
		throw std::runtime_error("DB is not properly formated");
	strptime(date.c_str(), "%Y-%m-%d", &time_struct);
	time_struct.tm_hour = 12;
    time_struct.tm_min = 0;
    time_struct.tm_sec = 0;
    time_struct.tm_isdst = -1;
	time = mktime(&time_struct);
	return (time);
}

std::string	timet_to_date_str(time_t time)
{
	char			buffer[11];
	struct tm 		time_struct;

	gmtime_r(&time, &time_struct);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &time_struct);
	return (std::string(buffer));
}