/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:14:12 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:14:13 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <string>
#include <iostream>
#define RED "\033[0;31m"
#define OFF "\033[0m"

int main (void)
{
	std::cout << RED << "**Form PresidentialPardonForm, B1-1, B2-67" << OFF << std::endl;
	try
	{
		Intern i;
		Form *f = i.makeForm("presidential pardon", "Mario");
		std::cout << *f;

		Bureaucrat b1 = Bureaucrat("Pippo", 1);
		b1.signForm(*f);
		f->execute(b1);
		b1.executeForm(*f);

		Bureaucrat b2 = Bureaucrat("Gino", 67);
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
		Form *f = i.makeForm("robotomy request", "MARIO");
		std::cout << *f;
		Bureaucrat b1 = Bureaucrat("Pippo", 5);
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
		Form *f = i.makeForm("shrubbery creation", "PEPPE");
		std::cout << *f;
		Bureaucrat b1 = Bureaucrat("Pippo", 50);
		b1.signForm(*f);
		f->execute(b1);
		delete (f);

		f = i.makeForm("shrubbery creation", "GIANNI");;
		Bureaucrat b2 = Bureaucrat("Gino", 105);
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
	i.makeForm("Ciao", "Pippo");

	return (0);
}
