/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:30:44 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 13:50:34 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <string>
# include <random>
# include "Zombie.hpp"

class   ZombieHorde
{
private:
    int     n;
    Zombie  *zombies;

public:
    ZombieHorde(int size);
    virtual ~ZombieHorde();

    void    announce(void);
};

#endif
