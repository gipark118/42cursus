/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:35:57 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 02:24:55 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy():
    hp(0), type(std::string())
{
}

Enemy::Enemy(int hp, std::string const &type):
    hp(hp), type(type)
{
}

Enemy::Enemy(Enemy const &other):
    hp(other.hp), type(other.type)
{
}

Enemy::~Enemy()
{
}

Enemy &Enemy::operator=(Enemy const &other)
{
    this->hp = other.hp;
    this->type = other.type;
    return (*this);
}

std::string const &Enemy::getType(void) const
{
    return (this->type);
}

int Enemy::getHP(void) const
{
    return (this->hp);
}

void Enemy::takeDamage(int damage)
{
    if (damage < 0)
        return ;
    this->hp -= damage;
    if (this->hp < 0)
        this->hp = 0;
}
