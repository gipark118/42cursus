/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:42:04 by gipark            #+#    #+#             */
/*   Updated: 2021/05/19 17:43:50 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "iter.hpp"

int main (void)
{

    int arr[] = {1, 4, 5, 42, 3, 2};
    ::iter(arr, 6, print);
    std::string arrs[] = {"Cat", "Dog", "Lion"};
    ::iter(arrs, 3, print);
    return (0);
}
