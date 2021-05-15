/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:11:57 by gipark            #+#    #+#             */
/*   Updated: 2021/05/15 21:26:33 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    FragTrap fr4g("FR4G-TP");
    ScavTrap sc4v("SC4V-TP");

    srand(time(NULL));
    fr4g.vaulthunter_dot_exe("Jackhammer");
    fr4g.meleeAttack("Jackhammer");
    fr4g.rangedAttack("Jackhammer");
    fr4g.takeDamage(30);
    fr4g.beRepaired(50);
    fr4g.takeDamage(42);
    fr4g.takeDamage(88);
    fr4g.beRepaired(142);
    fr4g.vaulthunter_dot_exe("Jackhammer");
    fr4g.vaulthunter_dot_exe("Jackhammer");
    fr4g.vaulthunter_dot_exe("Jackhammer");
    fr4g.vaulthunter_dot_exe("Jackhammer");
    fr4g.vaulthunter_dot_exe("Jackhammer");

    std::cout << "================" << std::endl;

    sc4v.challengeNewcomer();
    sc4v.meleeAttack("Taylor Kobb");
    sc4v.rangedAttack("Taylor Kobb");
    sc4v.takeDamage(17);
    sc4v.beRepaired(30);
    sc4v.takeDamage(42);
    sc4v.takeDamage(154);
    sc4v.beRepaired(274);
    sc4v.challengeNewcomer();
    sc4v.challengeNewcomer();
    sc4v.challengeNewcomer();
    sc4v.challengeNewcomer();
    return (0);
}
