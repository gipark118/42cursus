/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:59:25 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 16:01:45 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon      *weapon;

public:
    HumanB(std::string name);
    virtual ~HumanB();

    void        attack(void);
    void        setWeapon(Weapon &weapon);
};

#endif
