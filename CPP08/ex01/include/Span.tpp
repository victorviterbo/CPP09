/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:54:21 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/16 17:54:43 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Iter>
void	Span::addNumber(Iter begin, Iter end)
{
	//typename std::iterator_traits<Iter>::value_type;
	
	if (_size <= this->_nums.size() + (end - begin))
		throw std::overflow_error("Span container cannot add so many values");
	for (Iter it = begin; it != end; it++)
	{
		//try {
		this->_nums.push_back(*it);
		//}
		//catch (std::error)
		//	throw std::runtime_error("Value passed to container through iterator is not int");
	}
}