/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:04:30 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 03:29:19 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap():
    ClapTrap()
{
    this->hitPoints = 60;
    this->maxHitPoints = 60;
    this->energyPoints = 120;
    this->maxEnergyPoints = 120;
    this->level = 1;
    this->name = "CL4P-TP";
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 5;
    this->armorDamageReduction = 0;
    std::cout << "CL4P-TP(Default Trap): Revolutionizing....!!!" << std::endl;
}

NinjaTrap::NinjaTrap(std::string const &name):
    ClapTrap(name)
{
    this->hitPoints = 60;
    this->maxHitPoints = 60;
    this->energyPoints = 120;
    this->maxEnergyPoints = 120;
    this->level = 1;
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 5;
    this->armorDamageReduction = 0;
    std::cout << this->name << ": Revolutionizing....!!!" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &other):
    ClapTrap(other.name)
{
    this->hitPoints = other.hitPoints;
    this->maxHitPoints = other.maxHitPoints;
    this->energyPoints = other.energyPoints;
    this->maxEnergyPoints = other.maxEnergyPoints;
    this->level = other.level;
    this->meleeAttackDamage = other.meleeAttackDamage;
    this->rangedAttackDamage = other.rangedAttackDamage;
    this->armorDamageReduction = other.armorDamageReduction;
    std::cout << this->name << ": Revolutionizing....!!!" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
    std::cout << this->name << ": Now it's easier!" << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &other)
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

void NinjaTrap::meleeAttack(std::string const &target)
{
    std::cout << this->name << " kills "
            << target << " with a melee attack for "
            << this->meleeAttackDamage << " points of damage!" << std::endl;
}

void NinjaTrap::rangedAttack(std::string const &target)
{
    std::cout << this->name << " kills "
            << target << " with a range attack for "
            << this->rangedAttackDamage << " points of damage!" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &trap)
{
    std::cout << this->name << " tried to make a special attack on "
            << trap.getName() << " but failed!" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
    std::cout << this->name << " tried to make a special attack on "
            << trap.getName() << " but failed!!" << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
    std::cout << this->name << " tried to make a special attack on "
            << trap.getName() << " but failed!!!" << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
    std::cout << this->name << " tried to make a special attack on "
            << trap.getName() << " but failed!!!!" << std::endl;
}
