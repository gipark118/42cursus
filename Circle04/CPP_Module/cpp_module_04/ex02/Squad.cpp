/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 03:23:45 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 04:09:59 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad():
    count(0), units(NULL)
{
}

Squad::Squad(Squad const &other):
    count(0), units(NULL)
{
    int i;

    this->count = 0;
    i = 0;
    while (i < other.getCount())
    {
        this->push(other.getUnit(i)->clone());
        i++;
    }
}

Squad::~Squad()
{
    int i;

    i = 0;
    if (this->units)
    {
        while (i < this->count)
        {
            delete this->units[i];
            i++;
        }
        delete this->units;
    }
}

Squad &Squad::operator=(Squad const &other)
{
    int i;

    i = 0;
    if (this->units)
    {
        while (i < this->count)
        {
            delete this->units[i];
            i++;
        }
        delete this->units;
        this->units = NULL;
    }
    this->count = 0;
    i = 0;
    while (i < other.getCount())
    {
        this->push(other.getUnit(i)->clone());
        i++;
    }
    return (*this);
}

int Squad::getCount(void) const
{
    return (this->count);
}

ISpaceMarine* Squad::getUnit(int index) const
{
    if (this->count == 0 || index < 0 || index >= count)
        return (NULL);
    return (this->units[index]);
}

int Squad::push(ISpaceMarine *unit)
{
    int i;

    i = 0;
    if (!unit)
        return (this->count);
    if (this->units)
    {
        while (i < this->count)
        {
            if (this->units[i] == unit)
                return (this->count);
            i++;
        }
        ISpaceMarine **marine = new ISpaceMarine*[this->count + 1];
        i = 0;
        while (i < this->count)
        {
            marine[i] = this->units[i];
            i++;
        }
        delete[] this->units;
        this->units = marine;
        this->units[this->count] = unit;
        this->count++;
    }
    else
    {
        this->units = new ISpaceMarine*[1];
        this->units[0] = unit;
        this->count = 1;
    }
    return (this->count);
}
