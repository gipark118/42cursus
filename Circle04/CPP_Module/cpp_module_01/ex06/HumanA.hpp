/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:50:49 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 15:52:39 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon      &weapon;

public:
    HumanA(std::string name, Weapon &weapon);
    virtual ~HumanA();

    void        attack(void);
};

#endif
