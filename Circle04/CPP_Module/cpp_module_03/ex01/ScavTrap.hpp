/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:20:13 by gipark            #+#    #+#             */
/*   Updated: 2021/05/15 21:05:29 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

class ScavTrap
{
private:
    int hitPoints;
    int maxHitPoints;
    int energyPoints;
    int maxEnergyPoints;
    int level;
    std::string name;
    int meleeAttackDamage;
    int rangedAttackDamage;
    int armorDamageReduction;

public:
    ScavTrap();
    ScavTrap(std::string const &name);
    ScavTrap(ScavTrap const &other);
    virtual ~ScavTrap();

    ScavTrap &operator=(ScavTrap const &other);

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    bool takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void challengeNewcomer(void);
};

#endif
