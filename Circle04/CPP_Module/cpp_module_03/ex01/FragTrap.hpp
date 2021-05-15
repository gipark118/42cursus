/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:12:07 by gipark            #+#    #+#             */
/*   Updated: 2021/05/15 12:24:29 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>

class FragTrap
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
    FragTrap();
    FragTrap(std::string const &name);
    FragTrap(FragTrap const &other);
    virtual ~FragTrap();

    FragTrap &operator=(FragTrap const &other);

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    bool takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void vaulthunter_dot_exe(std::string const &target);
};

#endif
