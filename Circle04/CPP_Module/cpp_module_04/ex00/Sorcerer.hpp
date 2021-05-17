/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:15:56 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 23:05:15 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer
{
private:
    Sorcerer();
    
    std::string name;
    std::string title;

public:
    Sorcerer(std::string const &name, std::string const &title);
    Sorcerer(const Sorcerer& other);
    virtual ~Sorcerer();

    Sorcerer &operator=(const Sorcerer& other);

    std::string const &getName(void) const;
    std::string const &getTitle(void) const;

    void polymorph(Victim const &victim) const;
};

std::ostream &operator<<(std::ostream &out, Sorcerer const &sorcerer);

#endif
