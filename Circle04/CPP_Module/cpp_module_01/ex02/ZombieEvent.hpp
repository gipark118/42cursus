/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:43:39 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 13:11:11 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <string>
# include <random>
# include "Zombie.hpp"

class ZombieEvent
{
private:
    std::string type;

public:
    ZombieEvent();
    virtual ~ZombieEvent();

    void        setZombieType(std::string type);
    Zombie      *newZombie(std::string name);
    Zombie      *randomChump(void);
};

#endif
