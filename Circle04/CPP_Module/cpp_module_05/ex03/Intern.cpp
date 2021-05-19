/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:15:06 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 19:34:01 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern &Intern::operator = (const Intern &other)
{
    (void)other;
    return (*this);
}

Form *Intern::makeForm(std::string type, std::string target) const
{
    Form *list_form[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
    std::string list_name[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    Form *result = 0;
    for (int i = 0; i < 3; i++)
    {
        if (!type.compare(list_name[i]))
            result = list_form[i];
        else
            delete list_form[i];
    }
    if (!result)
        std::cout << "Form not found" << std::endl;
    else
        std::cout << "Intern creates " << type << std::endl;
    return result;
}
