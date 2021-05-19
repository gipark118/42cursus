/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:14:12 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 19:43:16 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#define RED "\033[0;31m"
#define OFF "\033[0m"

int main (void)
{
	std::cout << RED << "**Form PresidentialPardonForm, B1-1, B2-67" << OFF << std::endl;
	try
	{
		Intern i;
		Form *f = i.makeForm("presidential pardon", "Kim");
		std::cout << *f;

		Bureaucrat b1 = Bureaucrat("Han", 1);
		b1.signForm(*f);
		f->execute(b1);
		b1.executeForm(*f);

		Bureaucrat b2 = Bureaucrat("Baek", 67);
		b2.executeForm(*f);
		delete(f);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << RED << "**Form RobotomyRequestForm, B1-5, B2-100" << OFF << std::endl;
	try
	{
		Intern i;
		Form *f = i.makeForm("robotomy request", "Kim");
		std::cout << *f;
		Bureaucrat b1 = Bureaucrat("Han", 5);
		f->execute(b1);
		b1.executeForm(*f);
		b1.signForm(*f);
		f->execute(b1);
		b1.executeForm(*f);
		delete (f);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << RED << "**Form ShrubberyCreationForm, B1-50, B2-105" << OFF << std::endl;
	try
	{
		Intern i;
		Form *f = i.makeForm("shrubbery creation", "KIM");
		std::cout << *f;
		Bureaucrat b1 = Bureaucrat("Han", 50);
		b1.signForm(*f);
		f->execute(b1);
		delete (f);

		f = i.makeForm("shrubbery creation", "PARK");;
		Bureaucrat b2 = Bureaucrat("Baek", 105);
		b2.executeForm(*f);
		b1.signForm(*f);
		b2.executeForm(*f);
		delete(f);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << RED << "**Form Error Name" << OFF << std::endl;
	Intern i;
	i.makeForm("Seoul Form", "Hong");

	return (0);
}
