/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 05:38:31 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 14:31:16 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
public:
    Cure();
    Cure(Cure const &other);
    virtual ~Cure();

    Cure &operator=(Cure const &other);

    AMateria *clone(void) const;
    void use(ICharacter &target);
};

#endif
