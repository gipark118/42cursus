/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:47:31 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 15:48:50 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string type);
    virtual ~Weapon();
    
    void        setType(std::string type);
    std::string getType(void) const;
};

#endif
