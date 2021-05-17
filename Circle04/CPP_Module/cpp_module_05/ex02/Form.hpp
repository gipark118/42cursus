/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:53:19 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:11:06 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	protected:
		const std::string name;
		int gradeForSign;
		int gradeForExecute;
		bool isSigned;
		/* Default Constructor */
		Form() : name("empty"), gradeForSign(150), gradeForExecute(150), isSigned(false) {}
	public:
		/* Constructor */
		Form(std::string name, int gradeForSign, int gradeForExecute);
		/* Destructor */
		virtual ~Form();
		/* Copy Constructor */
		Form(const Form &other);
        /* Operation overload = */
		Form &operator = (const Form &other);
		/* Other */
		std::string getName(void) const;
		int getGradeForSign(void) const;
		int getGradeForExecute(void) const;
		bool getSigned(void) const;
		void beSigned(const Bureaucrat b);
		virtual void execute(const Bureaucrat& executor) const = 0;
		/* Exception */
		class GradeTooHighException : public std::exception
		{
			public:
			const char * what () const throw ()
			{
				return "Exception: Form grade too high";
			}
		};
		class GradeTooLowException : public std::exception
		{
			public:
			const char * what () const throw ()
			{
				return "Exception: Form grade too low";
			}
		};
};

std::ostream& operator << (std::ostream &output, const Form &obj);
