/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:08:58 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 12:49:39 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria():
    _type(NULL), _xp(0)
{
}

AMateria::AMateria(std::string const &type):
    _type(type), _xp(0)
{
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(AMateria const &other)
{
    this->_type = other._type;
    this->_xp = other._xp;
    return (*this);
}

std::string const &AMateria::getType(void) const
{
    return (this->_type);
}

unsigned int AMateria::getXP(void) const
{
    return (this->_xp);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
    this->_xp += 10;
}
