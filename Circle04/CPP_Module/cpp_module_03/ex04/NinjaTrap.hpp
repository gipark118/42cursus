/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:02:18 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 03:26:37 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap: virtual public ClapTrap
{
private:

public:
    NinjaTrap();
    NinjaTrap(std::string const &name);
    NinjaTrap(NinjaTrap const &other);
    virtual ~NinjaTrap();

    NinjaTrap &operator=(NinjaTrap const &other);

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    void ninjaShoebox(FragTrap &trap);
    void ninjaShoebox(ScavTrap &trap);
    void ninjaShoebox(ClapTrap &trap);
    void ninjaShoebox(NinjaTrap &trap);
};

#endif
