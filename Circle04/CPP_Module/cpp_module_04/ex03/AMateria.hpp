/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:49:07 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 12:51:02 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    AMateria();

    std::string _type;
    unsigned int _xp;

public:
    AMateria(std::string const &type);
    virtual ~AMateria();

    AMateria &operator=(AMateria const &other);

    std::string const &getType(void) const;
    unsigned int getXP(void) const;

    virtual AMateria *clone(void) const = 0;
    virtual void use(ICharacter& target);
};

#endif
