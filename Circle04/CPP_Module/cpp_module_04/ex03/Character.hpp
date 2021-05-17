/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 05:38:32 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 11:50:27 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
private:
    Character();

    std::string name;
    int equipped;
    AMateria *inventory[4];

public:
    Character(std::string const &name);
    Character(Character const &other);
    virtual ~Character();

    Character &operator=(Character const &other);

    std::string const &getName(void) const;

    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif
