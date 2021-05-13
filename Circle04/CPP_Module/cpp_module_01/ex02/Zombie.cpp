/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:47:07 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 13:14:19 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type)
{
    this->name = name;
    this->type = type;
    return ;
}

Zombie::~Zombie()
{
    std::cout << "<" << this->name << " (" << this->type << ")> is died.(delete)" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << "<" << this->name << " (" << this->type << ")>";
    std::cout << " Braiiiiiiinnnssss..." << std::endl;
    return ;
}
