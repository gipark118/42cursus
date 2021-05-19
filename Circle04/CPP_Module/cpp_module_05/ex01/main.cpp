/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:08:15 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 18:12:55 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#define RED "\033[0;31m"
#define OFF "\033[0m"

int main (void)
{
	std::cout << RED << "**Form 596" << OFF << std::endl;
	try
	{
		Form f = Form("F1", 596, 50);
		std::cout << f;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << RED << "**Bureaucrat 148, 50" << OFF << std::endl;
	try
	{
		Bureaucrat b = Bureaucrat("Jim", 148);
		std::cout << b;
		Form f = Form("F1", 50, 50);
		std::cout << f;
		b.signForm(f);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << RED << "**Bureaucrat 5, 109" << OFF << std::endl;
	try
	{
		Bureaucrat b = Bureaucrat("Jim", 5);
		std::cout << b;
		Form f = Form("F1", 109, 50);
		std::cout << f;
		b.signForm(f);
		std::cout << f;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
