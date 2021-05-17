/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:32:14 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 02:23:09 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include <string>

class Enemy
{
protected:
    Enemy();

    int hp;
    std::string type;

public:
    Enemy(int hp,std::string const &type);
    Enemy(Enemy const &other);
    virtual ~Enemy();

    Enemy &operator=(Enemy const &other);

    std::string const &getType(void) const;
    int getHP(void) const;

    virtual void takeDamage(int damage);
};

#endif
