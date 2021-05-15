/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:11:57 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 01:37:57 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap fr4g("FR4G-TP");

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

    return (0);
}
