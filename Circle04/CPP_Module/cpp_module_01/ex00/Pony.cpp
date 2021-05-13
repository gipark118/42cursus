/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:56:05 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 14:19:26 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string const &animal):
    animal(animal)
{
    std::cout << "# " << this->animal << " construction" << std::endl;
}

Pony::~Pony()
{
    std::cout << "# " << this->animal << " destruction" << std::endl;
}

void Pony::cry(void)
{
    std::cout << this->animal << "is crying!!" << std::endl;
}

void Pony::eat(void)
{
    std::cout << this->animal << "is eating!!" << std::endl;
}

void Pony::sleep(void)
{
    std::cout << this->animal << "is sleeping!!" << std::endl;
}
