/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 02:53:14 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 03:28:04 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad: public ISquad
{
private:
    int count;
    ISpaceMarine **units;

public:
    Squad();
    Squad(Squad const &other);
    virtual ~Squad();

    Squad &operator=(Squad const &other);

    int getCount(void) const;
    ISpaceMarine *getUnit(int index) const;

    int push(ISpaceMarine *unit);
};

#endif
