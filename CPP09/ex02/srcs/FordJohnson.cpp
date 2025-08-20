/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/08/20 17:11:24 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnson.hpp"

void	initial_split(std::deque<int> &vals, std::list<intpair> &initial)
{
	int		val1;
	int		val2;
	intpair	pair;

	while (vals.size())
	{
		val1 = vals.front();
		vals.pop_front();
		if (vals.empty())
		{
			pair.big = -1;
			pair.small = val1;
			initial.push_back(pair);
			return ;
		}
		val2 = vals.front();
		vals.pop_front();
		pair.big = (val1 > val2 ? val1 : val2);
		pair.small = (val1 < val2 ? val1 : val2);
		initial.push_back(pair);
	}
	return ;
}

void	generate_Jacobsthal(int n, std::deque<int> &q)
{
	q.push_front(0);
	q.push_front(1);
	while (q.front() < n)
		q.push_front(q[0] + 2 * q[1]);
}

int	getJacobsthal(int n)
{
	int val1 = 0;
	int val2 = 1;
	int	tmp;
	
	while (val2 < n)
	{
		tmp = val1;
		val1 = val2;
		val2 = val1 + 2 * tmp;
	}
	return (val2 - val1);
}

std::deque<int>	recursive_merge_insert(std::list<intpair> unsorted)
{
	std::map<int, std::list<intpair>::iterator>	pairing;
	std::list<intpair>							sorted;
	std::deque<int>								main;

	std::cout << "Entering recursion for size " << unsorted.size() << std::endl;
	if (unsorted.size() <= 1)
	{
		main.push_back(unsorted.front().big);
		return (main);
	}
	intpair							pair;
	std::list<intpair>::iterator	it = unsorted.begin();
	std::list<intpair>::iterator	nextIt = unsorted.begin();
	++nextIt;
	while (nextIt != unsorted.end() && it != unsorted.end())
	{
		pair.big = ((*it).big > (*nextIt).big ? (*it).big : (*nextIt).big);
		pair.small = ((*it).big < (*nextIt).big ? (*it).big : (*nextIt).big);
		sorted.push_back(pair);
		pairing[pair.big] = it;
		it = ++nextIt;
		++nextIt;
	}
	std::cout << "----- SORTED -------" << std::endl;
	for (std::list<intpair>::iterator it = sorted.begin(); it != sorted.end(); ++it)
		std::cout << (*it).small << ", " << (*it).big << std::endl;
	std::cout << std::endl;
	main = recursive_merge_insert(sorted);
	std::cout << "Back from recursion for size " << unsorted.size() << std::endl;
	std::cout << "----- MAIN -------" << std::endl;
	for (std::deque<int>::iterator it = main.begin(); it != main.end(); ++it)
		std::cout << *it << "\n";
	std::cout << std::endl;
	merge_into_main(main, sorted, pairing);
	return (main);
}

int	find_pair(int n, std::list<intpair> sorted)
{
	std::list<intpair>::iterator	it = sorted.begin();
	while (it != sorted.end())
	{
		if ((*it).big == n)
			return ((*it).small);
		++it;
	}
	throw std::runtime_error("Error: could not find pendant");
}

void	merge_into_main(std::deque<int> &main, std::list<intpair> sorted, std::map<int, std::list<intpair>::iterator>	pairing)
{
	size_t	last_jacob;
	size_t	jacob;
	size_t	tmp;
	
	std::cout << " entering merge_into_main" << std::endl;
	last_jacob = 0;
	jacob = 1;
	std::cout << "BEFORE" << std::endl;
	for (std::deque<int>::iterator it = main.begin(); it != main.end(); ++it)
		std::cout << *it << "\n";
	std::cout << "main over" << std::endl;

	for (std::list<intpair>::iterator it = sorted.begin(); it != sorted.end(); ++it)
		std::cout << (*it).small << "\n";
	std::cout << std::endl;

	while (jacob < sorted.size())
	{
		std::cout << "coucou ! jacob = " << jacob << std::endl;
		for (size_t i = jacob; i > last_jacob; i--)
			insert_into_main((*pairing[main[i - 1]]).small, main, i, jacob);
		tmp = jacob;
		jacob = jacob + 2 * last_jacob;
		last_jacob = tmp;
	}
	std::cout << "AFTER" << std::endl;
	for (std::deque<int>::iterator it = main.begin(); it != main.end(); ++it)
		std::cout << *it << "\n";
	std::cout << std::endl;

	for (std::list<intpair>::iterator it = sorted.begin(); it != sorted.end(); ++it)
		std::cout << (*it).small << "\n";
	std::cout << std::endl;
}

void	insert_into_main(int n,  std::deque<int> main, int i, int jacob)
{
	int	range_to_check = (jacob - 1) / 2;
		
	std::cout << "range_to_check = " << range_to_check << "i = " << i << std::endl;

	while (range_to_check)
	{
		if (n > main[i])
			i += range_to_check;
		else if (n < main[i])
			i -= range_to_check;
		range_to_check = std::ceil(range_to_check / 2);
	}
	std::deque<int>::iterator	it = main.begin();
	std::advance(it, i + 1);
	main.insert(it, n);
}