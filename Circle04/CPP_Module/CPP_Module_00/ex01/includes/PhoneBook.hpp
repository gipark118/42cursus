/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:49:32 by gipark            #+#    #+#             */
/*   Updated: 2021/05/12 03:15:31 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class       PhoneBook
{
private:
    int     index;
    Contact contacts[8];

public:
    PhoneBook();
    virtual ~PhoneBook();
    void    search(void);
    void    addContact(void);
    int     getIndex(void);
};

#endif
