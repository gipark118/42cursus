/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:53:21 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 00:12:21 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, int const signGrade, int const executeGrade):
    name(name), _signed(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &other):
    name(other.name), _signed(other._signed), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "FormException: Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "FormException: Grade Too Low";
}

Form &Form::operator=(Form const &other)
{
    this->_signed = other._signed;
    return (*this);
}

std::string const &Form::getName(void) const
{
	return (this->name);
}

bool Form::getIsSigned(void) const
{
	return (this->_signed);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int Form::getExecuteGrade(void) const
{
	return (this->executeGrade);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
        throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << "<# " << form.getName() << ((form.getIsSigned()) ? " is signed" : " is not signed");
    out << " # minimum value of sign: " << form.getSignGrade()
        << ", sign value for execution: " << form.getExecuteGrade() << ">";
    return (out);
}
