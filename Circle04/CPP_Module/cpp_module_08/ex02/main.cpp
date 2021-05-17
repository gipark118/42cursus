/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:40 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:43:41 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "mutantstack.hpp"
#include <list>

int main (void)
{
	std::cout << "*** MAIN SUBJECT" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << s.size() << std::endl;

	std::cout << "*** TEST ITERATORI" << std::endl;
	MutantStack<int> m;
	m.push(10);
	m.push(50);
	m.push(123);
	m.push(85);
	m.push(9);

	/* AVANTI */
	for (MutantStack<int>::iterator i = m.begin(); i != m.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	/* INDIETRO */
	for (MutantStack<int>::reverse_iterator i = m.rbegin(); i != m.rend(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	return (0);
}
