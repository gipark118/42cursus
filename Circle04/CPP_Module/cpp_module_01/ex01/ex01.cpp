/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:15:33 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 12:21:55 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void memoryLeak(void)
{
    std::string* panther = new std::string("String panther");

    std::cout << *panther << std::endl;
    delete panther;
}

int main(void)
{
    memoryLeak();
}
