/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 00:56:40 by gipark            #+#    #+#             */
/*   Updated: 2021/05/14 01:21:54 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int                 fixedPointValue;
    static const int    fractionalBits = 8;

public:
    Fixed();
    virtual ~Fixed();
    Fixed(Fixed const &other);

    Fixed   &operator=(Fixed const &other);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif
