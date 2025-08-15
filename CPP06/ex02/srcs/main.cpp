/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:09:24 by victorviter       #+#    #+#             */
/*   Updated: 2025/08/15 15:31:07 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base	*a = new A;
	Base	*mystery;

	mystery = Base::generate();
	Base::identify(a);
	Base::identify(*mystery);
	//Base::identify(b);
}