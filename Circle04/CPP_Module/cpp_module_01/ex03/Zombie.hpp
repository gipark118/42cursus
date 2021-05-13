/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:42:18 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 13:46:26 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
    std::string name;
    std::string type;

public:
    Zombie();
    Zombie(std::string name, std::string type);
    virtual ~Zombie();

    void        announce(void);
    void        setName(std::string name);
    void        setType(std::string type);
};

#endif
