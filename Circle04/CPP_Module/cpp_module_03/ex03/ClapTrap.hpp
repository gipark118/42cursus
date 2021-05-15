/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 00:31:54 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 03:17:08 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
protected:
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
    ClapTrap();
    ClapTrap(std::string const &name);
    ClapTrap(ClapTrap const &other);
    virtual ~ClapTrap();

    ClapTrap &operator=(ClapTrap const &other);

    virtual void meleeAttack(std::string const &target);
    virtual void rangedAttack(std::string const &target);
    bool takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    
    std::string const &getName(void);
};

#endif
