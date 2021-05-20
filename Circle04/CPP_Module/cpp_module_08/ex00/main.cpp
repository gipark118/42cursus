/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:09 by gipark            #+#    #+#             */
/*   Updated: 2021/05/20 11:42:31 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main (void)
{
	std::list<int> lists;
	lists.push_back(2);
	std::cout << "List ok" << std::endl;
	easyfind(lists, 2);
	std::cout << "List not ok" << std::endl;
	try
	{
		easyfind(lists, 10);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::vector<int> vec;
	vec.push_back(12);
	vec.push_back(14);
	std::cout << "Vector ok" << std::endl;
	easyfind(vec, 12);
	std::cout << "Vector not ok" << std::endl;
	try
	{
		easyfind(vec, 123);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::vector<int> vec_e;
	std::cout << "Vector empty" << std::endl;
	try
	{
		easyfind(vec_e, 12);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
