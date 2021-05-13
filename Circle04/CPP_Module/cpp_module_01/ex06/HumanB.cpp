/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:01:48 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 16:03:21 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    return ;
}

HumanB::~HumanB()
{
}

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with his " << (*this->weapon).getType() << std::endl;
    return ;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
    return ;
}
