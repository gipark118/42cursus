/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 00:56:41 by gipark            #+#    #+#             */
/*   Updated: 2021/05/14 01:21:26 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
}

Fixed::Fixed(Fixed const &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = other.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(Fixed const &other)
{
    std::cout << "Assignation operator called" << std::endl;
    this->fixedPointValue = other.getRawBits();
    return (*this);
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}
