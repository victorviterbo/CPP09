/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:54:21 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/28 16:44:47 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Span;

template <typename T>
void	Span::addNumber(T begin, T end)
{
	std::cout << "_size = " << this->_size << " _nums.size() = " << this->_nums.size() << std::endl;
	if (this->_size <= this->_nums.size() + (end - begin))
		throw std::overflow_error("Span container cannot add so many values");
	for (T it = begin; it != end; it++)
	{
		this->_nums.push_back(*it);
	}
}