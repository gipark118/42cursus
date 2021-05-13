/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 01:12:25 by gipark            #+#    #+#             */
/*   Updated: 2021/05/14 01:32:00 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}
