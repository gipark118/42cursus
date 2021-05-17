/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:14:58 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 00:32:02 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist():
    AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const &other):
    AWeapon(other)
{
}

PowerFist::~PowerFist()
{
}

PowerFist &PowerFist::operator=(PowerFist const &other)
{
    this->name = other.name;
    this->apCost = other.apCost;
    this->damage = other.damage;
    return (*this);
}

void PowerFist::attack(void) const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
