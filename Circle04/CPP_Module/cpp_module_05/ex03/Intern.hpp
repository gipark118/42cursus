/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:14:24 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 06:14:24 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "Form.hpp"

class Intern
{
	public:
    	/* Default Constructor */
		Intern();
		/* Destructor */
		~Intern();
		/* Copy Constructor */
		Intern(const Intern &other);
        /* Operation overload = */
		Intern &operator = (const Intern &other);
		/* Other */
        Form *makeForm(std::string type, std::string target) const;
};
