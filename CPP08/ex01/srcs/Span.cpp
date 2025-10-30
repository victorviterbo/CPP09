/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:01:24 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/30 12:14:33 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n)
{
	this->_size = n;
}

Span::Span(Span &other)
{
	this->_size = other._size;
	for (unsigned int i = 0; i < other._size; i++)
		this->_nums[i] = other._nums[i];
}

Span	&Span::operator=(Span &other)
{
	this->_nums.resize(0);
	this->_size = other._size;
	for (unsigned int i = 0; i < other._size; i++)
		this->_nums[i] = other._nums[i];
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int val)
{
	if (this->_nums.size() >= _size)
		throw std::overflow_error("Span container already full");
	this->_nums.push_back(val);
}

unsigned int	Span::shortestSpan()
{
	unsigned int		shortest;
	std::vector<int>	arr_copy(this->_size);

	arr_copy = this->_nums;
	std::sort(arr_copy.begin(), arr_copy.end());
	shortest = std::numeric_limits<unsigned int>::max();
	for (std::vector<int>::iterator it = arr_copy.begin(); it + 1 != arr_copy.end(); ++it)
	{
		if (shortest > static_cast<unsigned int>(*(it + 1) - *it))
			shortest = static_cast<unsigned int>(*(it + 1) - *it);
	}
	return (shortest);
}

unsigned int	Span::longestSpan()
{
	return (*std::max_element(this->_nums.begin(), this->_nums.end()) - *std::min_element(this->_nums.begin(), this->_nums.end()));
}

void			Span::printValues()
{
	for (std::vector<int>::iterator it = this->_nums.begin(); it != this->_nums.end(); ++it)
		std::cout << *it << std::endl;
}
