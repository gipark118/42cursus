/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 01:02:34 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 18:46:43 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:
        std::string target;

		RobotomyRequestForm() : Form("robotomy request", 72, 45), target("empty") {}

	public:
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	    void execute(const Bureaucrat& executor) const;
		std::string getTarget(void) const;
};

#endif
