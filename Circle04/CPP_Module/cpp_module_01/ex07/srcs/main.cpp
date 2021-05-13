/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 23:17:16 by gipark            #+#    #+#             */
/*   Updated: 2021/05/13 23:49:42 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char *argv[])
{
    std::string s1;
    std::string s2;
    std::string filename;

    if (argc != 4)
    {
        std::cerr << "## Please enter according to the below." << std::endl;
        std::cerr << "How to use: " << argv[0] << " filename string1 string2" << std::endl;
        return (1);
     }
     s1 = std::string(argv[2]);
     s2 = std::string(argv[3]);
     if (!s1.length() || !s2.length())
     {
         std::cerr << "Error: Empty string." << std::endl;
         return (1);
     }
     filename = std::string(argv[1]);
     return (Replace::replaceIn(filename, s1, s2));
}
