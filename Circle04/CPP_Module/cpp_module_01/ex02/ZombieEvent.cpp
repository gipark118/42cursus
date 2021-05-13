/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:54:40 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 13:12:30 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
    this->type = "infected";
    return ;
}

ZombieEvent::~ZombieEvent()
{
}

void        ZombieEvent::setZombieType(std::string type)
{
    this->type = type;
    return ;
}

Zombie      *ZombieEvent::newZombie(std::string name)
{
    return (new Zombie(name, this->type));
}

Zombie      *ZombieEvent::randomChump(void)
{
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

    return (new Zombie(names[dis(gen)], this->type));
}
