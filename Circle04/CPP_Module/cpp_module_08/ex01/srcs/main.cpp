/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:18 by gipark            #+#    #+#             */
/*   Updated: 2021/05/20 17:16:15 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"
#define RED "\033[0;31m"
#define OFF "\033[0m"

int main (void)
{
	try
	{
		std::cout << RED << "EMPTY Test" << OFF << std::endl;
		Span s0 = Span(20);
		s0.print();
		s0.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << RED << "ONE ELEMENT Test" << OFF << std::endl;
		Span s1 = Span(20);
		s1.addNumber(42);
		s1.print();
		s1.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << RED << "EASY Test" << OFF << std::endl;
	Span s2 = Span(10);
	s2.addNumber(-10);
	s2.addNumber(0);
	s2.addNumber(1);
	s2.addNumber(90);
	s2.print();
	std::cout << "SHORTEST: " << s2.shortestSpan() << std::endl;
	std::cout << "LONGEST: " << s2.longestSpan() << std::endl;
	std::cout << RED << "EASY2 Test" << OFF << std::endl;
	Span s3 = Span(100, 100);
	s3.print();
	std::cout << "SHORTEST: " << s3.shortestSpan() << std::endl;
	std::cout << "LONGEST: " << s3.longestSpan() << std::endl;
	std::cout << RED << "DIFFICULT Test" << OFF << std::endl;
	Span s4 = Span(10000, 10000);
	s4.print();
	std::cout << "SHORTEST: " << s4.shortestSpan() << std::endl;
	std::cout << "LONGEST: " << s4.longestSpan() << std::endl;
	return (0);
}
