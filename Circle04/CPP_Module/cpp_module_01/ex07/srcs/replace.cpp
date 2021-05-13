/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:10:12 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 23:54:19 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

Replace::Replace()
{
}

Replace::~Replace()
{
}

int Replace::replaceIn(std::string const &filename, std::string const &s1, std::string const &s2)
{
    size_t              current;
    std::ifstream       fin(filename);
    std::ofstream        fout;
    std::string         buffer;
    std::ostringstream  ss;

    if (!fin)
    {
        std::cerr << "Error: fatal" << std::endl;
        return (1);
    }
    fout.open(filename + ".replace");
    if (!fout)
    {
        std::cerr << "Error: fatal" << std::endl;
        return (1);
    }
    ss << fin.rdbuf();
    buffer = ss.str();
    current = buffer.find(s1);
    while (current != std::string::npos)
    {
        buffer.replace(current, s1.length(), s2);
        current = buffer.find(s1, current + s2.length());
    }
    fout << buffer;
    fout.close();
    fin.close();
    return (0);
}
