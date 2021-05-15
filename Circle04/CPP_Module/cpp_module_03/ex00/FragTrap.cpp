/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:12:05 by gipark            #+#    #+#             */
/*   Updated: 2021/05/15 21:28:37 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 100;
    this->maxEnergyPoints = 100;
    this->level = 1;
    this->name = "CL4P-TP";
    this->meleeAttackDamage = 30;
    this->rangedAttackDamage = 20;
    this->armorDamageReduction = 5;
    std::cout << "CL4P-TP(Default Trap): Installation Complete!!!" << std::endl;
}

FragTrap::FragTrap(std::string const &name):
    name(name)
{
    this->hitPoints = 100;
    this->maxHitPoints = 100;
    this->energyPoints = 100;
    this->maxEnergyPoints = 100;
    this->level = 1;
    this->meleeAttackDamage = 30;
    this->rangedAttackDamage = 20;
    this->armorDamageReduction = 5;
    std::cout << this->name << ": Installation Complete!!!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other):
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
    std::cout << this->name << ": Installation Complete!!!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << this->name << ": Aaaaaand... OPEN!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
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

void FragTrap::meleeAttack(std::string const &target)
{
    std::cout << this->name << " attacks "
            << target << " at melee, causing "
            << this->meleeAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::rangedAttack(std::string const &target)
{
    std::cout << this->name << " attacks "
            << target << " at range, causing "
            << this->rangedAttackDamage << " points of damage!" << std::endl;
}

bool FragTrap::takeDamage(unsigned int amount)
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

void FragTrap::beRepaired(unsigned int amount)
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

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    std::string attacks[5] = {
        "MinionTrap",
        "Mechomagician",
        "Funzerker",
        "Pirate ship mode",
        "Clap-In-The-Box"
    };

    if (this->energyPoints >= 25)
    {
        this->energyPoints -= 25;
        std::cout << this->name << ":: "
                << attacks[rand() % 5] << std::endl
                << this->name << " attacks "
                << target << " for " << ((rand() % this->meleeAttackDamage) + 1)
                << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "FR4G-TP " << this->name
                << " is out of energy!" << std::endl;
    }
}
