/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 23:12:07 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 01:06:28 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
private:

public:
    FragTrap();
    FragTrap(std::string const &name);
    FragTrap(FragTrap const &other);
    virtual ~FragTrap();

    FragTrap &operator=(FragTrap const &other);

    void meleeAttack(std::string const &target);
    void rangedAttack(std::string const &target);
    void vaulthunter_dot_exe(std::string const &target);
};

#endif
