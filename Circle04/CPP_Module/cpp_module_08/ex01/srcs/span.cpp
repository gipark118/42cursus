/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:27 by gipark            #+#    #+#             */
/*   Updated: 2021/05/20 17:02:06 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include "span.hpp"

Span::Span(unsigned int _N)
{
	this->N = _N;
	this->index = 0;
}

Span::Span(unsigned int _N, unsigned int cnt)
{
	this->N = _N;
	this->index = 0;
	if (cnt)
	{
		std::srand(time(0));
		for (unsigned int i = 0; i < this->N; i++)
			this->addNumber(std::rand() % cnt);
	}
}

Span::~Span()
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->N = other.N;
		this->index = other.index;
		this->array = other.array;
	}
	return (*this);
}

void Span::addNumber(int _n)
{
	if (this->index == this->N)
		throw Span::fullSpan();
	this->array.push_back(_n);
	this->index++;
}

int Span::shortestSpan(void) const
{
	if (this->index < 2)
		throw Span::notEnoughElement();
	unsigned int min = 4294967295;
	std::vector<int> temp = this->array;
	std::sort(temp.begin(), temp.end());
	for (unsigned int i = 0; i < this->index - 1; i++)
	{
		unsigned int distanza = std::abs(temp[i + 1] - temp[i]);
		if (distanza < min)
			min = distanza;
	}
	return min;
}

int Span::longestSpan(void) const
{
	if (this->index < 2)
		throw Span::notEnoughElement();
	int max = *std::max_element(this->array.begin(), this->array.end());
	int min = *std::min_element(this->array.begin(), this->array.end());
	return max - min;
}

void Span::print(void) const
{
	if (this->index == 0)
		std::cout << "Array: [ ]";
	else
	{
		std::cout << "Array: [";
		for (unsigned int i = 0; i < this->index; i++)
		{
			std::cout << this->array[i];
			if (i != this->index - 1)
				std::cout << ", ";
		}
		std::cout << "]";
	}
	std::cout << std::endl;
}
