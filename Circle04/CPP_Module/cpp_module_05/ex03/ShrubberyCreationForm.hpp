/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:14:35 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 19:28:43 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
    std::string target;

	ShrubberyCreationForm() : Form("shrubbery creation", 145, 137), target("empty") {}

public:
	ShrubberyCreationForm(std::string target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    void execute(const Bureaucrat& executor) const;
	std::string getTarget(void) const;
};

#endif
