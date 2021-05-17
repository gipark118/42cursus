/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:19:11 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:07:40 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		/* Default Constructor */
		Bureaucrat() {}
	public:
		/* Constructor */
		Bureaucrat(std::string name, int grade);
		/* Destructor */
		~Bureaucrat();
		/* Copy Constructor */
		Bureaucrat(const Bureaucrat &other);
        /* Operation overload = */
		Bureaucrat &operator = (const Bureaucrat &other);
		/* Other */
		std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		/* Exception */
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
