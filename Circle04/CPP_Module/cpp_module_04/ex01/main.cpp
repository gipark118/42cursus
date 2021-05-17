/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:49:11 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 02:49:14 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main(void)
{
    Character* me = new Character("me");

    std::cout << *me;

    Enemy* a = new SuperMutant();
    Enemy* b = new RadScorpion();

    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();

    me->equip(pr);
    std::cout << *me;
    me->equip(pf);

    me->attack(b);
    std::cout << *me;
    me->equip(pr);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    me->attack(b);          // delete RadScorpion
    std::cout << *me;
    me->attack(a);          // PlasmaRifle로 attack -> 21 - 3 데미지
    std::cout << *me;
    me->equip(pf);          // PowerFist 장착
    std::cout << *me;
    me->attack(a);          //  PowerFist로 attack -> 50 - 3 데미지
    std::cout << *me;
    me->attack(a);          // PowerFist로 attack -> 50 - 3 데미지
    std::cout << *me;
    me->recoverAP();        // AP 10 회복
    me->recoverAP();        // AP 10 회복
    std::cout << *me;
    me->attack(a);          // PowerFist로 attack -> 50 - 3 데미지
    std::cout << *me;
    me->attack(a);          // delete SuperMutant
    std::cout << *me;

    std::cout << std::endl;


    delete (me);
    delete (pr);
    delete (pf);

    return (0);
}
