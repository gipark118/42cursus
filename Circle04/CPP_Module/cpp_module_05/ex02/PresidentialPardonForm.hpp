/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 01:02:33 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 04:56:26 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
	PresidentialPardonForm();

	std::string const target;

public:
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	virtual ~PresidentialPardonForm();

	static std::string const &name;

	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

	void execute(Bureaucrat const &executor) const;
};

#endif
