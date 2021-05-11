/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 07:43:36 by gipark            #+#    #+#             */
/*   Updated: 2021/05/12 00:03:53 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void    command(std::string cmd, PhoneBook *phonebook)
{
    if (!cmd.compare("ADD"))
        phonebook->addContact();
    else if (!cmd.compare("SEARCH"))
        phonebook->search();
    else if (!cmd.compare("EXIT"))
        exit (EXIT_SUCCESS);
    return ;
}

int     main(void)
{
    std::string cmd;
    PhoneBook   phonebook;

    while (true)
    {
        std::cout << "Please Enter a Command [ADD, SEARCH, EXIT]" << std::endl;
        std::cin >> cmd;
        command(cmd, &phonebook);
    }
    return (0);
}
