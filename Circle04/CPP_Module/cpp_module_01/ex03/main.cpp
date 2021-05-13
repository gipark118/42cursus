/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:49:44 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 13:52:16 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int     main(void)
{
    ZombieHorde horde = ZombieHorde(13);

    std::cout << "ZombieHorde is coming..." << std::endl;
    horde.announce();
    return (0);
}
