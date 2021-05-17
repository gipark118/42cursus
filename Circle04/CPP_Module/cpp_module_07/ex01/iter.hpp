/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:41:59 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:41:59 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>

template <class T> void iter(T array[], int size, void (*f)(T const &))
{
	for (int i = 0; i < size; i++)
	{
		(*f)(array[i]);
	}
}

template <typename T> void stampa(T const &ele)
{
	std::cout << ele << std::endl;
}
