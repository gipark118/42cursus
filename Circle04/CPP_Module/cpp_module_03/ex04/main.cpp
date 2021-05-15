/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:11:57 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 04:07:23 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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

    std::cout << "================" << std::endl;

    ClapTrap cl4p("CL4P");
    NinjaTrap *ninj4 = new NinjaTrap("NINJ4-TP");
    ninj4->ninjaShoebox(*ninj4);
    ninj4->meleeAttack("Hyperion Dump");
    ninj4->rangedAttack("Hyperion Dump");
    ninj4->takeDamage(24);
    ninj4->beRepaired(50);
    ninj4->takeDamage(42);
    ninj4->takeDamage(100);
    ninj4->beRepaired(125);
    ninj4->ninjaShoebox(*fr4g);
    ninj4->ninjaShoebox(*fr4g);
    ninj4->ninjaShoebox(*fr4g);
    ninj4->ninjaShoebox(cl4p);
    ninj4->ninjaShoebox(*sc4v);
    ninj4->ninjaShoebox(*sc4v);
    ninj4->ninjaShoebox(*sc4v);
    ninj4->ninjaShoebox(*sc4v);
    ninj4->ninjaShoebox(cl4p);

    std::cout << "================" << std::endl;

    SuperTrap *su4r = new SuperTrap("SU4R-TP");
	su4r->ninjaShoebox(*ninj4);
	su4r->ninjaShoebox(*fr4g);
	su4r->meleeAttack("Jim");
	su4r->rangedAttack("Jim");
	su4r->takeDamage(17);
	su4r->beRepaired(30);
	su4r->takeDamage(42);
	su4r->takeDamage(154);
	su4r->beRepaired(274);
	su4r->vaulthunter_dot_exe("Jim");
	su4r->vaulthunter_dot_exe("Jim");
	su4r->ninjaShoebox(*fr4g);
	su4r->ninjaShoebox(*fr4g);
	su4r->ninjaShoebox(cl4p);
	su4r->ninjaShoebox(*sc4v);
	su4r->ninjaShoebox(*sc4v);
	su4r->ninjaShoebox(*sc4v);
	su4r->ninjaShoebox(cl4p);
    std::cout << std::endl;

    delete (fr4g);
    delete (sc4v);
    delete (ninj4);
    delete (su4r);
    return (0);
}
