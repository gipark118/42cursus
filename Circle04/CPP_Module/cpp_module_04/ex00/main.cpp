/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 08:15:40 by gipark            #+#    #+#             */
/*   Updated: 2021/05/16 23:44:07 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main(void)
{
    Sorcerer voldemort("Voldemort", "the Deathly Hallows");

    Victim harry("Harry");
    Peon doby("Doby");

    std::cout << voldemort << harry << doby;

    voldemort.polymorph(harry);
    harry.getPolymorphed();
    voldemort.polymorph(doby);
    doby.getPolymorphed();
    voldemort.polymorph(static_cast<Victim>(doby));

    std::cout << std::endl;

    Sorcerer tom(voldemort);

    Victim james(harry);
    Peon bellatrix(doby);

    std::cout << tom << james << bellatrix;

    james = harry;
    tom.polymorph(james);
    james.getPolymorphed();
    tom = voldemort;
    bellatrix = doby;
    tom.polymorph(bellatrix);
    bellatrix.getPolymorphed();

    std::cout << std::endl;

    return (0);
}
