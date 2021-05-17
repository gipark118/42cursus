/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:08:15 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 22:51:00 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat jim("Jim", 42);

    std::cout << jim << std::endl;
    jim.incrementGrade();
    std::cout << jim << std::endl;
    jim.decrementGrade();
    std::cout << jim << std::endl;

    std::cout << std::endl;

    try
    {
        Bureaucrat carrey("Carrey", 0);
        std::cout << carrey << std::endl;
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat carrey("Carrey", 1);
        std::cout << carrey << std::endl;
        carrey.incrementGrade();
        std::cout << carrey << std::endl;
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat carrey("Carrey", 150);
        std::cout << carrey << std::endl;
        carrey.decrementGrade();
        std::cout << carrey << std::endl;
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
