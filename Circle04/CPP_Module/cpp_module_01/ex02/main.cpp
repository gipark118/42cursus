/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:31:54 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 13:13:00 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void)
{
    Zombie      *zombie_one;
    Zombie      *zombie_two;
    ZombieEvent event;

    event.setZombieType("non-infected");
    zombie_one = event.newZombie("Dongjin");
    zombie_one->announce();
    delete(zombie_one);     // not needed anymore
    zombie_two = event.randomChump();
    zombie_two->announce();
    delete(zombie_two);     // not needed anymore
    return (0);
}
