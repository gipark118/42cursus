/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:55:07 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 14:48:46 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name):
    name(name), equipped(0)
{
    int i;

    i = 0;
    while (i < 4)
        this->inventory[i++] = NULL;

}

Character::Character(Character const &other):
    name(other.name), equipped(0)
{
    int i;

    i = 0;
    while (i < other.equipped)
        this->equip(other.inventory[i++]->clone());
    i = this->equipped;
    while (i < 4)
        this->inventory[i++] = NULL;
}

Character::~Character()
{
    int i;

    i = 0;
    while (i < this->equipped)
        delete this->inventory[i++];
}

Character &Character::operator=(Character const &other)
{
    int i;

    this->name = other.name;
    i = 0;
    while (i < this->equipped)
        delete this->inventory[i++];
    this->equipped = 0;
    i = 0;
    while (i < other.equipped)
        this->equip(other.inventory[i++]->clone());
    i = this->equipped;
    while (i < 4)
        this->inventory[i++] = NULL;
    return (*this);
}

std::string const &Character::getName(void) const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
    int  i;

    i = 0;
    if (this->equipped == 4 || m == NULL)
        return ;
    while (i < this->equipped)
    {
        if (this->inventory[i] == m)
            return ;
        i++;
    }
    this->inventory[this->equipped++] = m;
}

void Character::unequip(int idx)
{
    int i;

    i = idx;
    if (idx < 0 || idx >= this->equipped || this->inventory[idx] == NULL)
        return ;
    while (i < 3)
    {
        this->inventory[i] = this->inventory[i + 1];
        this->inventory[i + 1] = NULL;
        i++;
    }
    this->equipped--;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= this->equipped || this->inventory[idx] == NULL)
        return ;
    this->inventory[idx]->use(target);
}
