/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:14:27 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 19:27:10 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
    std::string target;

	PresidentialPardonForm() : Form("presidential pardon", 25, 5), target("empty") {}
    
public:
	PresidentialPardonForm(std::string target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    void execute(const Bureaucrat& executor) const;
	std::string getTarget(void) const;
};

#endif
