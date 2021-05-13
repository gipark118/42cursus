/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:06:16 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 12:14:33 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheStack(void)
{
    Pony onTheStack("Lion");
    onTheStack.cry();
    onTheStack.eat();
    onTheStack.sleep();
}

void ponyOnTheHeap(void)
{
    Pony *onTheHeap;

    onTheHeap = new Pony("Tiger");
    onTheHeap->cry();
    onTheHeap->eat();
    onTheHeap->sleep();
    delete onTheHeap;
}

int main(void)
{
    std::cout << "[[ ponyOnTheStack]]" << std::endl;
    ponyOnTheStack();
    std::cout << std::endl;
    std::cout << "[[ ponyOnTheHeap]]" << std::endl;
    ponyOnTheHeap();
    std::cout << "-------------------------" << std::endl;
    return (0);
}
