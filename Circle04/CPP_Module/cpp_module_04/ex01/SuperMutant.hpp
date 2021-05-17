/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:43:09 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 00:44:51 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant: public Enemy
{
public:
    SuperMutant();
    SuperMutant(SuperMutant const &other);
    virtual ~SuperMutant();

    SuperMutant &operator=(SuperMutant const &other);

    void takeDamage(int damage);
};

#endif
