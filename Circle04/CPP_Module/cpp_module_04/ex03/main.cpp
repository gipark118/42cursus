/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 05:38:25 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 15:02:27 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(1, *bob);
    me->use(1, *bob);
    me->use(1, *bob);
    std::cout << "exp: " << tmp->getXP() << std::endl;
    me->use(0, *bob);

    me->unequip(0);
    me->use(0, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "====" << std::endl;

    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());

    ICharacter* we = new Character("we");
    ICharacter* jim = new Character("jim");
    AMateria* mat;
    mat = src2->createMateria("ice");
    we->equip(mat);
    mat = src2->createMateria("cure");
    we->equip(mat);
    mat = src2->createMateria("ice");
    we->equip(mat);
    mat = src2->createMateria("cure");
    we->equip(mat);

    we->use(0, *jim);
    we->use(1, *jim);
    we->use(2, *jim);
    we->use(3, *jim);

    delete jim;
    delete we;
    delete src2;

    return 0;
}
