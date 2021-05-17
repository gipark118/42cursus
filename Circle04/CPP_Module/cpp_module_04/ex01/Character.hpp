/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:03:24 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 01:12:11 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
    Character();

    std::string name;
    int ap;
    AWeapon *weapon;

public:
    Character(std::string const &name);
    Character(Character const &other);
    virtual ~Character();

    Character &operator=(Character const &other);

    std::string const &getName(void) const;
    int getAP(void) const;
    AWeapon *getWeapon(void) const;

    void recoverAP(void);
    void equip(AWeapon *weapon);
    void attack(Enemy *enemy);
};

std::ostream &operator<<(std::ostream &out, Character const &character);

#endif
