/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:40 by gipark            #+#    #+#             */
/*   Updated: 2021/05/20 18:01:38 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "mutantstack.hpp"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define OFF "\033[0m"

int main (void)
{
	std::cout << RED << "MAIN TEST" << OFF << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(42);
	std::cout << GREEN << "top in stack: " << OFF << mstack.top() << std::endl;
	std::cout << GREEN << "stack size: " << OFF << mstack.size() << std::endl;
	mstack.pop();
	std::cout << GREEN << "after pop, stack size: " << OFF << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(42);
	mstack.push(311);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << GREEN << "in stack: " << OFF;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	std::cout << GREEN << "stack size: " << OFF << s.size() << std::endl;

	std::cout << RED << "ITERATOR TEST" << OFF << std::endl;
	MutantStack<int> m;
	m.push(13);
	m.push(49);
	m.push(231);
	m.push(85);
	m.push(7);

	/* Forward */
	std::cout << GREEN << "in stack: " << OFF;
	for (MutantStack<int>::iterator i = m.begin(); i != m.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	/* Reverse */
	std::cout << GREEN << "After reverse, in stack: " << OFF;
	for (MutantStack<int>::reverse_iterator i = m.rbegin(); i != m.rend(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	return (0);
}
