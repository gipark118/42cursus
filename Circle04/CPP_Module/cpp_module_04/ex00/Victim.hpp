/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:15:59 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 23:05:17 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim
{
protected:
    Victim();

    std::string name;

public:
    Victim(std::string const &name);
    Victim(const Victim& other);
    virtual ~Victim();

    Victim &operator=(const Victim& other);

    std::string const &getName(void) const;
    virtual void getPolymorphed(void) const;
};

std::ostream &operator<<(std::ostream &out, Victim const &victim);

#endif
