/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:14:17 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 19:24:57 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string name;
	int grade;

	Bureaucrat() {}

public:
	Bureaucrat(std::string name, int grade);
	virtual ~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);

	Bureaucrat &operator=(const Bureaucrat &other);

	std::string getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(Form &f) const;
	void executeForm(const Form &form);

	class GradeTooHighException : public std::exception
	{
		public:
		const char * what () const throw ()
		{
			return "Exception: Bureaucrat grade too high";
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char * what () const throw ()
		{
			return "Exception: Bureaucrat grade too low";
		}
	};
};

std::ostream& operator << (std::ostream &output, const Bureaucrat &obj);

#endif
