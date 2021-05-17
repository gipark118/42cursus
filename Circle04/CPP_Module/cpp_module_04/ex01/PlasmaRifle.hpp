/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:06:29 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 00:08:40 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
public:
    PlasmaRifle();
    PlasmaRifle(PlasmaRifle const &other);
    virtual ~PlasmaRifle();

    PlasmaRifle &operator=(PlasmaRifle const &other);

    void attack(void) const;
};

#endif
