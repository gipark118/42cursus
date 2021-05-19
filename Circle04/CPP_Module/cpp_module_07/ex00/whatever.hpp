/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:12:24 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 15:13:21 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <class T> void swap (T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T> T min (T a, T b) {
    if (a < b)
        return a;
    else
        return b;
}

template <class T> T max (T a, T b) {
    if (a > b)
        return a;
    else
        return b;
}

#endif
