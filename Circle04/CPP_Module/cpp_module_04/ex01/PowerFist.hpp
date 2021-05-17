/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:09:06 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 02:23:25 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist: public AWeapon
{
public:
    PowerFist();
    PowerFist(PowerFist const &other);
    virtual ~PowerFist();

    PowerFist &operator=(PowerFist const &other);

    void attack(void) const;
};

#endif
