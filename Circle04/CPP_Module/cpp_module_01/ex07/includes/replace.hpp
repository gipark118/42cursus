/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:30:22 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 23:51:28 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class Replace
{
public:
    Replace();
    virtual ~Replace();

    static int replaceIn(std::string const &filename, std::string const &s1, std::string const &s2);
};

#endif
