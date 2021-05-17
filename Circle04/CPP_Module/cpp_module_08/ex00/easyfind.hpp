/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:01 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:43:02 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <exception>
#include <algorithm>

class ElementoNonTrovato: public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Elemento non trovato");
		}
};

template <typename T> void easyfind (T &data, int n)
{
	if (std::find(data.begin(), data.end(), n) != data.end())
		std::cout << "Elemento trovato" << std::endl;
	else
		throw ElementoNonTrovato();
}
