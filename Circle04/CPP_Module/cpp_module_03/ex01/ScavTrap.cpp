/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:00:04 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 01:25:01 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 100;
    this->maxEnergyPoints = 100;
    this->level = 1;
    this->name = "CL4P-TP";
    this->meleeAttackDamage = 20;
    this->rangedAttackDamage = 15;
    this->armorDamageReduction = 3;
    std::cout << this->name << "I'm a Claptrap unit in Borderlands: The Pre-Sequel who operates in service to a scav gang." << std::endl;
}

ScavTrap::ScavTrap(std::string const &name):
    name(name)
{
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 100;
    this->maxEnergyPoints = 100;
    this->level = 1;
    this->meleeAttackDamage = 20;
    this->rangedAttackDamage = 15;
    this->armorDamageReduction = 3;
    std::cout << this->name << " I'm a Claptrap unit in Borderlands: The Pre-Sequel who operates in service to a scav gang." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other):
    name(other.name)
{
    this->hitPoints = other.hitPoints;
    this->maxHitPoints = other.maxHitPoints;
    this->energyPoints = other.energyPoints;
    this->maxEnergyPoints = other.maxEnergyPoints;
    this->level = other.level;
    this->meleeAttackDamage = other.meleeAttackDamage;
    this->rangedAttackDamage = other.rangedAttackDamage;
    this->armorDamageReduction = other.armorDamageReduction;
    std::cout << this->name << "I'm a Claptrap unit in Borderlands: The Pre-Sequel who operates in service to a scav gang." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->name << ": Bye, Serena, my love!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
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

void ScavTrap::meleeAttack(std::string const &target)
{
    std::cout << this->name << " makes a melee attacks to "
            << target << " causing "
            << this->meleeAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target)
{
    std::cout << this->name << " makes a ranged attack to "
            << target << " causing "
            << this->rangedAttackDamage << " points of damage!" << std::endl;
}

bool ScavTrap::takeDamage(unsigned int amount)
{
    int dmg = amount - this->armorDamageReduction;
    this->hitPoints -= dmg;
    if (this->hitPoints < 0)
    {
        dmg += this->hitPoints;
        this->hitPoints = 0;
    }
    std::cout << this->name << " takes "
            << dmg << " points of damage!" << std::endl;
    return (this->hitPoints == 0);
}

void ScavTrap::beRepaired(unsigned int amount)
{
    int heal = amount;
    this->hitPoints += amount;
    if (this->hitPoints > this->maxHitPoints)
    {
        heal -= (this->hitPoints - this->maxHitPoints);
        this->hitPoints = this->maxHitPoints;
    }
    std::cout << this->name << " is repaired for "
            << heal << "!" << std::endl;
}

void ScavTrap::challengeNewcomer(void)
{
    std::string challenges[5] = {
        "Making a threatening water gun",
        "Making coke bombs",
        "Automatically detect",
        "Write self-destructing code",
        "Manning the gate"
    };

    std::cout << this->name << ": ";
    std::cout << challenges[rand() % 5] << std::endl;
}
