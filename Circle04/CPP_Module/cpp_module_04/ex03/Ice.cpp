/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:29:38 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 14:02:19 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():
    AMateria("ice")
{
}

Ice::Ice(Ice const &other):
    AMateria("ice")
{
    this->_xp = other._xp;
}

Ice::~Ice()
{
}

Ice &Ice::operator=(Ice const &other)
{
    this->_type = "ice";
    this->_xp = other._xp;
    return (*this);
}

AMateria *Ice::clone(void) const
{
    Ice *i = new Ice(*this);
    return (i);
}

void Ice::use(ICharacter &target)
{
    AMateria::use(target);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
