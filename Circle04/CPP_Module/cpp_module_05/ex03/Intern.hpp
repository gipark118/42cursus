/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:14:24 by gipark            #+#    #+#             */
/*   Updated: 2021/05/18 19:26:32 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"

class Intern
{
public:
	Intern();
	virtual ~Intern();
	Intern(const Intern &other);

	Intern &operator = (const Intern &other);

    Form *makeForm(std::string type, std::string target) const;
};

#endif
