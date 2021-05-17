/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:09 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:43:09 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "easyfind.hpp"
#include <list>
#include <vector>

int main (void)
{
	std::list<int> lista;
	lista.push_back(2);
	std::cout << "LISTA OK" << std::endl;
	easyfind(lista, 2);
	std::cout << "LISTA NOT OK" << std::endl;
	try
	{
		easyfind(lista, 10);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::vector<int> vettore;
	vettore.push_back(12);
	vettore.push_back(14);
	std::cout << "VETTORE OK" << std::endl;
	easyfind(vettore, 12);
	std::cout << "VETTORE NOT OK" << std::endl;
	try
	{
		easyfind(vettore, 123);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::vector<int> vettore_vuoto;
	std::cout << "VETTORE VUOTO" << std::endl;
	try
	{
		easyfind(vettore_vuoto, 12);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
