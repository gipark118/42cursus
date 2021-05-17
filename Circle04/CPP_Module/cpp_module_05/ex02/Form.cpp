/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:53:21 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:13:04 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeForSign, int gradeForExecute) : name(name), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute), isSigned(false) {
	if (this->gradeForSign < 1 || this->gradeForExecute < 1)
		throw Form::GradeTooHighException();
	if (this->gradeForSign > 150 || this->gradeForExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other) : name(other.name), gradeForSign(other.gradeForSign), gradeForExecute(other.gradeForExecute)
{
	*this = other;
}

Form &Form::operator = (const Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
		this->gradeForSign = other.gradeForSign;
		this->gradeForExecute = other.gradeForExecute;
	}
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->name);
}

int Form::getGradeForSign(void) const
{
	return (this->gradeForSign);
}

int Form::getGradeForExecute(void) const
{
	return (this->gradeForExecute);
}

bool Form::getSigned(void) const
{
	return (this->isSigned);
}

void Form::beSigned(const Bureaucrat b)
{
	if (b.getGrade() > this->gradeForSign)
		throw Form::GradeTooLowException();
	else
		this->isSigned = true;
}

std::ostream& operator << (std::ostream &output, const Form &obj)
{
	output << "----------------------------" << std::endl;
	output << "Form: " << obj.getName() << std::endl;
	output << "Grade Sign: " << obj.getGradeForSign() << std::endl;
	output << "Grade Execute: " << obj.getGradeForExecute() << std::endl;
	if (obj.getSigned())
		output << "Is Signed: TRUE" << std::endl;
	else
		output << "Is Signed: FALSE" << std::endl;
	output << "----------------------------" << std::endl;
	return (output);
}
