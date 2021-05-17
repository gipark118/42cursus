/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:53:52 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 00:56:51 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion: public Enemy
{
public:
    RadScorpion();
    RadScorpion(RadScorpion const &other);
    virtual ~RadScorpion();

    RadScorpion &operator=(RadScorpion const &other);
};

#endif
