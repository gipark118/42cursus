/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:24:48 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 14:41:59 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource():
    amount(0)
{
    int i;

    i = 0;
    while (i < 4)
        this->sources[i++] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other):
    amount(0)
{
    int i;

    i = 0;
    while (i < other.amount)
        this->learnMateria(other.sources[i++]->clone());
    i = 0;
    while (i < 4)
        this->sources[i++] = NULL;
}

MateriaSource::~MateriaSource()
{
    int i;

    i = 0;
    while (i < this->amount)
        delete this->sources[i++];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
    int i;

    i = 0;
    while (i < this->amount)
        delete this->sources[i++];
    this->amount = 0;
    i = 0;
    while (i < other.amount)
        this->learnMateria(other.sources[i++]->clone());
    i = 0;
    while (i < 4)
        this->sources[i++] = NULL;
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    int i;

    i = 0;
    if (this->amount == 4 || m == NULL)
        return ;
    while (i < this->amount)
    {
        if (this->sources[i] == m)
            return ;
        i++;
    }
    this->sources[this->amount++] = m;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    int i;

    i = 0;
    while (i < this->amount)
    {
        if (this->sources[i]->getType() == type)
            return (this->sources[i]->clone());
        i++;
    }
    return (NULL);
}
