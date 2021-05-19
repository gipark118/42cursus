/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:14:21 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 19:25:58 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
protected:
	const std::string name;
	int gradeForSign;
	int gradeForExecute;
	bool isSigned;

	Form() : name("empty"), gradeForSign(150), gradeForExecute(150), isSigned(false) {}
	
public:
	Form(std::string name, int gradeForSign, int gradeForExecute);
	virtual ~Form();
	Form(const Form &other);

	Form &operator=(const Form &other);

	std::string getName(void) const;
	int getGradeForSign(void) const;
	int getGradeForExecute(void) const;
	bool getSigned(void) const;
	void beSigned(const Bureaucrat b);
	virtual void execute(const Bureaucrat& executor) const = 0;

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

#endif
