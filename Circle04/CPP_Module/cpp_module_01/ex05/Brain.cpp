/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:38:28 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 14:41:58 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::stringstream ss;

    ss << this;
    this->address = ss.str();
    return ;
}

Brain::~Brain()
{
}

std::string Brain::identify(void) const
{
    return (this->address);
}
