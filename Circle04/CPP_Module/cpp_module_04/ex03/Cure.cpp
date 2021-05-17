/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:44:04 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 14:02:24 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure():
    AMateria("cure")
{
}

Cure::Cure(Cure const &other):
    AMateria("cure")
{
    this->_xp = other._xp;
}

Cure::~Cure()
{
}

Cure &Cure::operator=(Cure const &other)
{
    this->_type = "cure";
    this->_xp = other._xp;
    return (*this);
}

AMateria *Cure::clone(void) const
{
    Cure *c = new Cure(*this);
    return (c);
}

void Cure::use(ICharacter &target)
{
    AMateria::use(target);
    std::cout << "* heals " << target.getName() << "s wounds *" << std::endl;
}
