/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 05:38:29 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 14:31:11 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
public:
    Ice();
    Ice(Ice const &other);
    virtual ~Ice();

    Ice &operator=(Ice const &other);

    AMateria *clone(void) const;
    void use(ICharacter &target);
};

#endif
