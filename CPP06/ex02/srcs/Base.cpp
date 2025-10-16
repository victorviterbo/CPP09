/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:31:27 by victorviter       #+#    #+#             */
/*   Updated: 2025/10/16 14:52:12 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int		seed()
{
	struct timespec t;
	clock_gettime(CLOCK_REALTIME, &t);
	return (t.tv_nsec);
}

Base::~Base() {}

Base	*Base::generate(void)
{
	Base	*ret;

	srand(seed());
	int n = rand() % 3;
	if (n == 0)
		ret = new A;
	else if (n == 1)
		ret = new B;
	else if (n == 2)
		ret = new C;
	else
	{
		ret = NULL;
		std::cout << "Error while generating the random value" << std::endl;
	}
	return (ret);
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Given pointer references derived class A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Given pointer references derived class B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Given pointer references derived class C" << std::endl;
}

void Base::identify(Base& p)
{
	int	i = 0;

	while (i < 3)
	{
		try {
		if (i == 0)
		{
			(void)dynamic_cast<A &>(p);
			std::cout << "Given references is an instance of derived class A" << std::endl;
			break ;
		}
		if (i == 1)
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "Given references is an instance of derived class B" << std::endl;
			break ;
		}
		if (i == 2)
		{
			(void)dynamic_cast<C &>(p);
			std::cout << "Given references is an instance of derived class C" << std::endl;
			break ;
		}
		}
		catch (std::exception &e){
			i++;
			if (i == 3)	
				std::cout << "Given reference is not a known class" << std::endl;
		}
	}
}
