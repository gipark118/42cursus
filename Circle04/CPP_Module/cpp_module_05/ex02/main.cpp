/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:08:15 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 05:23:26 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL));

	Bureaucrat park("park", 1);
	std::cout << park << std::endl;
	Bureaucrat lee("lee", 25);
	std::cout << lee << std::endl;

	Form *shrub = new ShrubberyCreationForm("testfile");
	std::cout << *shrub << std::endl;
	shrub->beSigned(park);
	shrub->execute(lee);

	Form *kim = new PresidentialPardonForm("kim");
	std::cout << *kim << std::endl;
	park.signForm(*kim);
	kim->execute(park);

	Form *robotomy = new RobotomyRequestForm("robo");
	std::cout << *robotomy << std::endl;
	robotomy->beSigned(park);
	robotomy->execute(lee);
	lee.executeForm(*robotomy);
	lee.executeForm(*robotomy);

	std::cout << "---" << std::endl;

	try
	{
		lee.executeForm(*kim);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		RobotomyRequestForm robotomy = RobotomyRequestForm("robo");
		std::cout << robotomy << std::endl;
		robotomy.execute(park);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		PresidentialPardonForm kim = PresidentialPardonForm("lee");
		std::cout << kim << std::endl;
		park.signForm(kim);
		kim.execute(lee);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---" << std::endl;

	try
	{
		PresidentialPardonForm kim = PresidentialPardonForm("lee");
		std::cout << kim << std::endl;
		park.signForm(kim);
		lee.executeForm(kim);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete shrub;
	delete kim;
	delete robotomy;

	return (0);
}
