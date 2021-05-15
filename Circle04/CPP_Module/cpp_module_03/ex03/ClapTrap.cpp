/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 00:31:25 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 03:17:20 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->hitPoints = 0;
    this->maxHitPoints = 0;
    this->energyPoints = 0;
    this->maxEnergyPoints = 0;
    this->level = 0;
    this->name = "CL4P-TP";
    this->meleeAttackDamage = 0;
    this->rangedAttackDamage = 0;
    this->armorDamageReduction = 0;
    std::cout << "CL4P-TP(default trap): Initializing....!!!" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name):
    name(name)
{
    this->hitPoints = 0;
    this->maxHitPoints = 0;
    this->energyPoints = 0;
    this->maxEnergyPoints = 0;
    this->level = 0;
    this->meleeAttackDamage = 0;
    this->rangedAttackDamage = 0;
    this->armorDamageReduction = 0;
    std::cout << "ClapTrap " << name << ": Initializing....!!!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other):
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
    std::cout << "ClapTrap " << name << ": Installation Complete!!!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
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

void ClapTrap::meleeAttack(std::string const &target)
{
    std::cout << "ClapTrap " << this->name << " attacks "
            << target << " at melee, causing "
            << this->meleeAttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::rangedAttack(std::string const &target)
{
    std::cout << "ClapTrap " << this->name << " attacks "
            << target << " at range, causing "
            << this->rangedAttackDamage << " points of damage!" << std::endl;
}

bool ClapTrap::takeDamage(unsigned int amount)
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

void ClapTrap::beRepaired(unsigned int amount)
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

std::string const &ClapTrap::getName(void)
{
	return (this->name);
}
