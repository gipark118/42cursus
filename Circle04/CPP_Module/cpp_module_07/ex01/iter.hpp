/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:41:59 by gipark            #+#    #+#             */
/*   Updated: 2021/05/19 17:36:39 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class T> void iter(T array[], int size, void (*f)(T const &))
{
	for (int i = 0; i < size; i++)
	{
		(*f)(array[i]);
	}
}

template <typename T> void print(T const &ele)
{
	std::cout << ele << std::endl;
}

#endif
