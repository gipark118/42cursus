/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:48:55 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 15:50:30 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
    return ;
}

Weapon::~Weapon()
{
}

void    Weapon::setType(std::string type)
{
    this->type = type;
    return ;
}

std::string Weapon::getType(void) const
{
    return (this->type);
}
