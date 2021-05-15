/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:20:13 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 01:17:59 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
private:

public:
    ScavTrap();
    ScavTrap(std::string const &name);
    ScavTrap(ScavTrap const &other);
    virtual ~ScavTrap();

    ScavTrap &operator=(ScavTrap const &other);

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    void challengeNewcomer(void);
};

#endif
