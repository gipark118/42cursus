/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:52:48 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 04:10:59 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap():
    ClapTrap()
{
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 120;
    this->maxEnergyPoints = 120;
    this->level = 1;
    this->name = "CL4P-TP";
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 20;
    this->armorDamageReduction = 5;
    std::cout << "CL4P-TP(Default Trap): Super~~~~Trap!" << std::endl;
}

SuperTrap::SuperTrap(std::string const &name):
    ClapTrap(name), NinjaTrap(name), FragTrap(name)
{
    this->hitPoints = this->FragTrap::hitPoints;
	this->maxHitPoints = this->FragTrap::maxHitPoints;
	this->energyPoints = this->NinjaTrap::energyPoints;
	this->maxEnergyPoints = this->NinjaTrap::maxEnergyPoints;
    this->level = 1;
	this->meleeAttackDamage = this->NinjaTrap::meleeAttackDamage;
	this->rangedAttackDamage = this->FragTrap::rangedAttackDamage;
	this->armorDamageReduction = this->FragTrap::armorDamageReduction;
    std::cout << this->name << ": Super~~~~Trap!" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &other):
    ClapTrap(other.name), NinjaTrap(other.name), FragTrap(other.name)
{
    this->hitPoints = other.hitPoints;
    this->maxHitPoints = other.maxHitPoints;
    this->energyPoints = other.energyPoints;
    this->maxEnergyPoints = other.maxEnergyPoints;
    this->level = other.level;
    this->meleeAttackDamage = other.meleeAttackDamage;
    this->rangedAttackDamage = other.rangedAttackDamage;
    this->armorDamageReduction = other.armorDamageReduction;
    std::cout << this->name << ": Super~~~~Trap!" << std::endl;
}

SuperTrap::~SuperTrap()
{
    std::cout << this->name << ": Ultimate assault shoebox" << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &other)
{
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->maxHitPoints = other.maxHitPoints;
    this->energyPoints = other.energyPoints;
    this->maxEnergyPoints = other.maxEnergyPoints;
    this->level = other.level;
    this->meleeAttackDamage = other.meleeAttackDamage;
    this->rangedAttackDamage = other.rangedAttackDamage;
    this->armorDamageReduction = other.armorDamageReduction;
    return (*this);
}

void SuperTrap::rangedAttack(std::string const &target)
{
    FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const &target)
{
    NinjaTrap::meleeAttack(target);
}
