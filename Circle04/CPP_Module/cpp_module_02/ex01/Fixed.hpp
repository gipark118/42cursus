/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 00:56:40 by gipark            #+#    #+#             */
/*   Updated: 2021/05/14 02:07:52 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int                 fixedPointValue;
    static const int    fractionalBits = 8;

public:
    Fixed();
    virtual ~Fixed();
    Fixed(Fixed const &other);
    Fixed(int const num);
    Fixed(float const num);

    Fixed   &operator=(Fixed const &other);

    float   toFloat(void) const;
    int     toInt(void) const;
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, Fixed const &other);

#endif
