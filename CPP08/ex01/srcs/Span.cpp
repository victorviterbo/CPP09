/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:01:24 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/14 18:54:38 by victorviter      ###   ########.fr       */
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
	if (_size <= this->_nums.size())
		throw std::overflow_error("Span container already full");
	this->_nums.push_back(val);
}

unsigned int	Span::shortestSpan()
{
	unsigned int	shortest;

	shortest = std::numeric_limits<unsigned int>::max();
	if (!std::is_sorted(this->_nums.begin(), this->_nums.end()))
		std::sort(this->_nums.begin(), this->_nums.end());
	for (std::vector<int>::iterator it = this->_nums.begin(); it != this->_nums.end(); ++it)
	{
		if (shortest > static_cast<unsigned int>(*(it + 1) - *it))
			shortest = static_cast<unsigned int>(*(it + 1) - *it);
	}
	return (shortest);
}

unsigned int	Span::longestSpan()
{
	if (!std::is_sorted(this->_nums.begin(), this->_nums.end()))
		std::sort(this->_nums.begin(), this->_nums.end());
	return (*(this->_nums.end() - 1) - *(this->_nums.begin()));
}

void	Span::printValues()
{
	for (std::vector<int>::iterator it = this->_nums.begin(); it != this->_nums.end(); ++it)
		std::cout << *it << std::endl;
}
