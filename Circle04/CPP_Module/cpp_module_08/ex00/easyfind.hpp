/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:43:01 by gipark            #+#    #+#             */
/*   Updated: 2021/05/20 12:00:39 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

class notFoundElememt: public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Exception: Not Found element.");
		}
};

template <typename T> void easyfind (T &data, int n)
{
	if (std::find(data.begin(), data.end(), n) != data.end())
		std::cout << "Found element." << std::endl;
	else
		throw notFoundElememt();
}

#endif
