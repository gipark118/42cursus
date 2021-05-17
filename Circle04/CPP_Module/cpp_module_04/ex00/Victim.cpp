/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:15:58 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 23:44:35 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string const &name):
    name(name)
{
    std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::Victim(Victim const &other):
    name(other.name)
{
    std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->name << " just died for no apparent reason!" << std::endl;
}

Victim &Victim::operator=(Victim const &other)
{
    this->name = other.name;
    return (*this);
}

std::string const &Victim::getName(void) const
{
    return (this->name);
}

void Victim::getPolymorphed(void) const
{
    std::cout << this->name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Victim const &victim)
{
    out << "I'm " << victim.getName() << " and I like otters!" << std::endl;
    return (out);
}
