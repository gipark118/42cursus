/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:18 by gipark            #+#    #+#             */
/*   Updated: 2021/05/20 11:59:32 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"

int main (void)
{
	try
	{
		std::cout << "*** EMPTY" << std::endl;
		Span s0 = Span(20);
		s0.print();
		s0.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "*** EASY" << std::endl;
	Span s1 = Span(10);
	s1.addNumber(-10);
	s1.addNumber(0);
	s1.addNumber(1);
	s1.addNumber(90);
	s1.print();
	std::cout << "SHORT: " << s1.shortestSpan() << std::endl;
	std::cout << "LONG: " << s1.longestSpan() << std::endl;
	std::cout << "*** EASY" << std::endl;
	Span s2 = Span(100, true);
	s2.print();
	std::cout << "SHORT: " << s2.shortestSpan() << std::endl;
	std::cout << "LONG: " << s2.longestSpan() << std::endl;
	std::cout << "*** DIFFICULT" << std::endl;
	Span s3 = Span(10000, true);
	s3.print();
	std::cout << "SHORT: " << s3.shortestSpan() << std::endl;
	std::cout << "LONG: " << s3.longestSpan() << std::endl;
	return (0);
}
