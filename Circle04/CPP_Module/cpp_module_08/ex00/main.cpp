/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:09 by gipark            #+#    #+#             */
/*   Updated: 2021/05/20 17:16:31 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"
#define RED "\033[0;31m"
#define OFF "\033[0m"

int main (void)
{
	std::list<int> lists;
	lists.push_back(42);
	lists.push_front(24);
	std::cout << RED << "list Found Test" << OFF << std::endl;
	easyfind(lists, 42);
	easyfind(lists, 24);
	std::cout << std::endl;
	std::cout << RED << "List Not Found Test" << OFF << std::endl;
	try
	{
		easyfind(lists, 10);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::vector<int> vec;
	vec.push_back(24);
	vec.push_back(42);
	std::cout << RED << "Vector Found Test" << OFF << std::endl;
	easyfind(vec, 24);
	std::cout << std::endl;
	std::cout << RED << "Vector Not Found Test" << OFF << std::endl;
	try
	{
		easyfind(vec, 2442);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::vector<int> vec_e;
	std::cout << RED << "Vector Empty Test" << OFF << std::endl;
	try
	{
		easyfind(vec_e, 12);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
