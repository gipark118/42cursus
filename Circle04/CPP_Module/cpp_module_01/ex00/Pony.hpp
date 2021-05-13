/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:50:47 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 12:11:47 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>

class Pony
{
private:
    std::string const &animal;
public:
    Pony(std::string const &animal);
    virtual ~Pony();

    void cry(void);
    void eat(void);
    void sleep(void);
};

#endif
