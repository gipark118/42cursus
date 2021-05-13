/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:28:43 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 13:50:37 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int size)
{
    this->zombies = new Zombie[size];
    std::string names[11] = {
        "Yuri",
        "Junho",
        "Yeseul",
        "Dongsuk",
        "Narae",
        "Junhyung",
        "Myungjun",
        "Saebom",
        "Chanyoung",
        "Aram",
        "Hyunji"
    };
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 10);

    this->n = 0;
    while (this->n < size)
    {
        this->zombies[this->n].setName(names[dis(gen)]);
        this->zombies[this->n].setType("infected");
        n++;
    }
    return ;
}

ZombieHorde::~ZombieHorde()
{
    std::cout << "# ZombieHorde is died.(delete)" << std::endl;
    delete[] this->zombies;
}

void        ZombieHorde::announce(void)
{
    int     i;

    i = 0;
    while (i < this->n)
        this->zombies[i++].announce();
    return ;
}
