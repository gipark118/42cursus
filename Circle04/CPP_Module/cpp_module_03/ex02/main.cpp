/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:11:57 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 01:30:27 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    srand(time(NULL));
    FragTrap *fr4g = new FragTrap("FR4G-TP");
    fr4g->vaulthunter_dot_exe("Jackhammer");
    fr4g->meleeAttack("Jackhammer");
    fr4g->rangedAttack("Jackhammer");
    fr4g->takeDamage(30);
    fr4g->beRepaired(50);
    fr4g->takeDamage(42);
    fr4g->takeDamage(88);
    fr4g->beRepaired(142);
    fr4g->vaulthunter_dot_exe("Jackhammer");
    fr4g->vaulthunter_dot_exe("Jackhammer");
    fr4g->vaulthunter_dot_exe("Jackhammer");
    fr4g->vaulthunter_dot_exe("Jackhammer");
    fr4g->vaulthunter_dot_exe("Jackhammer");
    delete (fr4g);

    std::cout << "================" << std::endl;

    ScavTrap *sc4v = new ScavTrap("SC4V-TP");
    sc4v->challengeNewcomer();
    sc4v->meleeAttack("Taylor Kobb");
    sc4v->rangedAttack("Taylor Kobb");
    sc4v->takeDamage(17);
    sc4v->beRepaired(30);
    sc4v->takeDamage(42);
    sc4v->takeDamage(154);
    sc4v->beRepaired(274);
    sc4v->challengeNewcomer();
    sc4v->challengeNewcomer();
    sc4v->challengeNewcomer();
    sc4v->challengeNewcomer();
    delete (sc4v);

    return (0);
}
