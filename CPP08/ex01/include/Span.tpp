/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:54:21 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 18:50:51 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Span;

template <typename T>
void	Span::addNumber(T begin, T end)
{
	if (_size <= this->_nums.size() + (end - begin))
		throw std::overflow_error("Span container cannot add so many values");
	for (T it = begin; it != end; it++)
	{
		this->_nums.push_back(*it);
	}
}