/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 03:48:33 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 03:52:00 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include <string>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap: public NinjaTrap, public FragTrap
{
private:

public:
    SuperTrap();
    SuperTrap(std::string const &name);
    SuperTrap(SuperTrap const &other);
    virtual ~SuperTrap();

    SuperTrap &operator=(SuperTrap const &other);

    void rangedAttack(std::string const &target);
    void meleeAttack(std::string const &target);
};

#endif
