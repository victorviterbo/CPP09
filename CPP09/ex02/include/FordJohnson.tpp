/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FordJohnson.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:02:46 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/09 13:57:38 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FordJohnson.hpp"

template < typename T>
void	recursiveMergeInsert(T &main, T &mixed, unsigned int level)
{
	blockSort(mixed, level);
	if (pow(2, level + 1) <= mixed.size())
	{
		recursiveMergeInsert(main, mixed, level + 1);
		T	predecessors(0);
		size_t	idx = pow(2, level) - 1;
		while (idx < mixed.size())
		{
			predecessors.push_back(mixed[idx]);
			idx += pow(2, level + 1);
		}
		mergeInMain(main, predecessors);
	}
	else
		main.insert(main.begin(), mixed[pow(2, level) - 1]);
	return ;
}

template < typename T >
void	blockSort(T &mixed, unsigned int level)
{

	T						semiSorted;
	size_t					idx_l;
	size_t					idx_r;
	typename T::iterator	r1_start;
	typename T::iterator	r2_start;
	typename T::iterator	r2_end;
	
	idx_l = static_cast<size_t>(pow(2, level) - 1);
	idx_r = static_cast<size_t>(pow(2, level + 1) - 1);
	semiSorted.resize(0);
	while (idx_r < mixed.size())
	{
		r1_start = mixed.begin();
		r2_start = mixed.begin();
		r2_end = mixed.begin();
		std::advance(r1_start, static_cast<int>(idx_l - pow(2, level) + 1));
		std::advance(r2_start, static_cast<int>(idx_l + 1));
		std::advance(r2_end, static_cast<int>(idx_r + 1));
		if (mixed[idx_l] < mixed[idx_r])
		{
			semiSorted.insert(semiSorted.end(), r1_start, r2_start);
			semiSorted.insert(semiSorted.end(), r2_start , r2_end);
		}
		else
		{
			semiSorted.insert(semiSorted.end(), r2_start, r2_end);
			semiSorted.insert(semiSorted.end(), r1_start, r2_start);
		}
		idx_l += static_cast<size_t>(pow(2, level + 1));
		idx_r += static_cast<size_t>(pow(2, level + 1));
	}
	r2_end = mixed.begin();
	std::advance(r2_end, semiSorted.size());
	semiSorted.insert(semiSorted.end(), r2_end, mixed.end());
	mixed = semiSorted;
	semiSorted.clear();
	return ;
}

template < typename T >
void	initialInsert(T &main, T &predecessors, T &global_mapping)
{
	int		pos = 0;
	main.insert(main.begin(), predecessors[0]);
	global_mapping.push_back(0);
	global_mapping.push_back(1);
	typename T::iterator it1 = main.begin();
	typename T::iterator it2 = global_mapping.begin();
	if (predecessors.size() > 1)
	{
		if (main[0] < predecessors[1])
		{
			if (main[1] <predecessors[1])
				pos = 2;
			else
				pos = 1;
		}
		std::advance(it1, pos);
		main.insert(it1, predecessors[1]);
		std::advance(it2, pos);
		global_mapping.insert(it2, 2);
	}
}

template < typename T >
void	mergeInMain(T &main, T &predecessors)
{
	typename T::iterator	it;
	T						insert_mapping(0);
	T						tmp_mapping(main.size());
	static T				global_mapping(0);
	size_t					i = 0;
	int						indx;
	int						insert_pos;
	size_t					main_orig_size = main.size();

	for (unsigned int j = 0; j < main.size() + predecessors.size(); ++j)
		insert_mapping.push_back(j);
	if (global_mapping.size() == 0)
	{
		initialInsert(main, predecessors, global_mapping);
		return ;
	}
	for (unsigned int k = 0; k < tmp_mapping.size(); ++k)
		tmp_mapping[k] = global_mapping[k] * 2 + 1;
	while (i < insertionOrder_d.size() && i < 3 * predecessors.size())
	{
		if (static_cast<int>(predecessors.size()) < insertionOrder_d[i])
		{
			++i;
			continue ;
		}
		else if (static_cast<int>(predecessors.size()) == insertionOrder_d[i] && predecessors.size() != main_orig_size)
		{
			insert_pos = main.size();
			indx = predecessors.size() - 1;
		}
		else
		{
			insert_pos = insert_mapping[insertionOrder_d[i] - 1];
			indx = global_mapping[insertionOrder_d[i] - 1];
		}
		insert_pos = insertIntoMain(main, predecessors[indx], insert_pos);
		for (unsigned int j = 0; j < insert_mapping.size(); ++j)
		{
			if (insert_mapping[j] >= insert_pos)
				insert_mapping[j] += 1;
		}
		it = tmp_mapping.begin();
		std::advance(it, insert_pos);
		tmp_mapping.insert(it, indx * 2);
		++i;
	}
	global_mapping = tmp_mapping;
}

template < typename T >
size_t	insertIntoMain(T &main, int n, size_t indx)
{
	typename T::iterator	it = main.begin();
	size_t						rl = 0;
	size_t						ru = indx;
	size_t						mid;

	while (rl + 1 < ru)
	{
		mid = (ru + rl) / 2;
		if (main[mid] < n)
			rl = mid;
		else
			ru = mid;
	}
	if (main[rl] < n)
		indx = rl + 1;
	else
		indx = rl;
	std::advance(it, indx);
	main.insert(it, n);
	return (indx);
}
