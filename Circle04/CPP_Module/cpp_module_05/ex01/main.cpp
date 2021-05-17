/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:08:15 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 01:01:26 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat jim("Jim", 42);
	std::cout << jim << std::endl;

	Form form1("carrey1", 100, 10);
	std::cout << form1 << std::endl;
	form1.beSigned(jim);
	std::cout << form1 << std::endl;

	std::cout << "=======" << std::endl;

	Form form2("carrey2", 40, 10);
	std::cout << form2 << std::endl;
	try
	{
		jim.signForm(form2);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "=======" << std::endl;

	Form form3("carrey3", 50, 10);
	std::cout << form3 << std::endl;
	jim.signForm(form3);

	std::cout << "=======" << std::endl;

	try
	{
		Form form4("carrey4", 40, 10);
		std::cout << form4 << std::endl;
		form4.beSigned(jim);
		std::cout << form4 << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << "=======" << std::endl;

    try
    {
        Form form5("range", 0, 50);
        std::cout << form5 << std::endl;
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "=======" << std::endl;

    try
    {
        Form form5_1("range", 0, 4242);
        std::cout << form5_1 << std::endl;
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "=======" << std::endl;

    try
    {
        Form form5_2("range", 42, 0);
        std::cout << form5_2 << std::endl;
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }

	return (0);
}
