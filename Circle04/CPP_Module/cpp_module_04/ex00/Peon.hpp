/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:15:53 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 23:04:47 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon: public Victim
{
private:
    Peon();
    
public:
    Peon(std::string const &name);
    Peon(Peon const &peon);
    virtual ~Peon();

    Peon &operator=(const Peon& other);

    void getPolymorphed(void) const;
};

#endif
