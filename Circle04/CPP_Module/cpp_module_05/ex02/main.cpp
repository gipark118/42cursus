/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:08:15 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 19:43:26 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#define RED "\033[0;31m"
#define OFF "\033[0m"

int main (void)
{
	std::cout << RED << "**Form PresidentialPardonForm(25, 5), B1-1, B2-67" << OFF << std::endl;
	try
	{
		PresidentialPardonForm f = PresidentialPardonForm("Kim");
		std::cout << f;
		Bureaucrat b1 = Bureaucrat("Han", 1);
		b1.signForm(f);
		f.execute(b1);
		b1.executeForm(f);

		Bureaucrat b2 = Bureaucrat("Baek", 67);
		b2.executeForm(f);
		f.execute(b2);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << RED << "**Form RobotomyRequestForm(72, 45), B1-5, B2-100" << OFF << std::endl;
	try
	{
		RobotomyRequestForm f = RobotomyRequestForm("Kim");
		std::cout << f;
		Bureaucrat b1 = Bureaucrat("Han", 5);
		f.execute(b1);
		b1.executeForm(f);
		b1.signForm(f);
		f.execute(b1);
		b1.executeForm(f);

		Bureaucrat b2 = Bureaucrat("Baek", 100);
		b2.executeForm(f);
		f.execute(b2);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << RED << "**Form ShrubberyCreationForm(145, 137), B1-50, B2-105" << OFF << std::endl;
	try
	{
		ShrubberyCreationForm f = ShrubberyCreationForm("KIM");
		std::cout << f;
		Bureaucrat b1 = Bureaucrat("Han", 50);
		b1.signForm(f);
		f.execute(b1);

		ShrubberyCreationForm f2 = ShrubberyCreationForm("PARK");
		Bureaucrat b2 = Bureaucrat("Baek", 105);
		b2.executeForm(f2);
		b1.signForm(f2);
		b2.executeForm(f2);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
