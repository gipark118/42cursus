/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:05:10 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 14:38:18 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

int main(void)
{
    Human bob;

    std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
    return (0);
}
