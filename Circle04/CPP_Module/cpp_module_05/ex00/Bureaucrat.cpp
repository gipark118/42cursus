/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:19:09 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 22:37:07 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade):
    name(name), grade(grade)
{
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other):
    name(other.name), grade(other.grade)
{
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "BureaucratException: Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "BureaucratException: Grade Too Low";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    this->grade = other.grade;
    return (*this);
}

std::string const &Bureaucrat::getName(void) const
{
    return (this->name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
    this->grade--;
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
    this->grade++;
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (out); 
}
