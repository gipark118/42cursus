/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:30 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:43:32 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <vector>

class Span
{
	private:
		unsigned int N;
		std::vector<int> array;
		unsigned int index;
		/* Default Constructor */
		Span() {}
	public:
		/* Constructor */
		Span(unsigned int _N);
		Span(unsigned int _N, bool _random);
		/* Destructor */
		~Span();
		/* Copy Constructor */
		Span(const Span &other);
        /* Operation overload = */
		Span &operator = (const Span &other);
		/* Other */
		void addNumber(int _n);
		int shortestSpan(void) const;
		int longestSpan(void) const;
		void stampa(void) const;
		/* Exception */
		class SpanPieno : public std::exception
		{
			public:
			const char * what () const throw ()
			{
				return "Span pieno";
			}
		};
		class PochiElementi : public std::exception
		{
			public:
			const char * what () const throw ()
			{
				return "Non ci sono abbastanza elementi per la funzione";
			}
		};
};
