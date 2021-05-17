/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:41:37 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:42:29 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
