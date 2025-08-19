/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:32:10 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/19 12:36:39 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.hpp"

bool	is_non_zero(std::string s)
{
	if (s[0] != '0' && s[0] != '-')
		return (true);
	for (unsigned int i = 1; i < s.length(); ++i)
	{
		if (s[i] != '0')
			return (true);
	}
	return (false);
}
