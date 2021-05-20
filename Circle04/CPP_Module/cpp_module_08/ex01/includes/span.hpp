/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:30 by gipark            #+#    #+#             */
/*   Updated: 2021/05/20 17:02:11 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <exception>
# include <vector>

class Span
{
private:
	unsigned int N;
	std::vector<int> array;
	unsigned int index;

	Span() {}

public:
	Span(unsigned int _N);
	Span(unsigned int _N, unsigned int cnt);
	virtual ~Span();
	Span(const Span &other);

	Span &operator=(const Span &other);

	void addNumber(int _n);
	int shortestSpan(void) const;
	int longestSpan(void) const;
	void print(void) const;

	class fullSpan : public std::exception
	{
		public:
		const char * what () const throw ()
		{
			return "Span is full";
		}
	};
	class notEnoughElement : public std::exception
	{
		public:
		const char * what () const throw ()
		{
			return "There are not enough elements for the function";
		}
	};
};

#endif
