/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:53:19 by gipark            #+#    #+#             */
/*   Updated: 2021/05/17 23:42:37 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
class Form;
# include "Bureaucrat.hpp"

class Form
{
private:
    Form();

    std::string const &name;
    bool _signed;
    int const signGrade;
    int const executeGrade;

public:
    Form(std::string const &name, int const signGrade, int const executeGrade);
    Form(Form const &other);
    virtual ~Form();

    class GradeTooHighException: public std::exception {
        virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception {
        virtual const char* what() const throw();
    };

    Form &operator=(Form const &other);

    std::string const &getName(void) const;
    bool getIsSigned(void) const;
    int getSignGrade(void) const;
    int getExecuteGrade(void) const;

    void beSigned(Bureaucrat const &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
