/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:05:27 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 23:11:30 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string const &name):
    Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &other):
    Victim(other.name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

Peon &Peon::operator=(Peon const &other)
{
    this->name = other.name;
    return (*this);
}

void Peon::getPolymorphed(void) const
{
    std::cout << this->name << " has been turned into a pink pony!" << std::endl;
}
