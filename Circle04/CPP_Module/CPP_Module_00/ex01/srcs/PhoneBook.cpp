/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:04:14 by gipark            #+#    #+#             */
/*   Updated: 2021/05/12 03:37:06 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->index = 0;
}

PhoneBook::~PhoneBook()
{
}

void        PhoneBook::search(void)
{
    int     i;

    if (!this->index)
    {
        std::cout << "#####       Contact is empty.       #####" << std::endl;
        return ;
    }
    i = 0;
    std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
    while (i < this->index)
    {
        std::cout << "|" << std::setw(10) << i;
        this->contacts[i].display_list();
        i++;
    }
    std::cout << "###    Please enter the index number.    ###" << std::endl;
    while (!(std::cin >> i) || (i < 0 || i >= 8))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "###            Invalid Index              ###" << std::endl;
        std::cout << "Re-enter: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (i >= 0 && i < this->index)
    {
        std::cout << "index: " << i << std::endl;
        this->contacts[i].display_info();
    }
    else
        std::cout << "###   The index number does not exist.   ###" << std::endl;
    std::cin.clear();
    return ;
}

void        PhoneBook::addContact(void)
{
    std::string input;
    Contact     *contact;

    if (this->index == 8)
    {
        std::cout << "PhoneBook is full." << std::endl;
        return ;
    }
    contact = &this->contacts[this->index];
    std::cout << "[[       Contact Form       ]]" << std::endl;
    std::cout << "first name: ";
    std::cin >> input;
    contact->setFirstName(input);
    std::cout << "last name: ";
    std::cin >> input;
    contact->setLastName(input);
    std::cout << "nickname: ";
    std::cin >> input;
    contact->setNickname(input);
    std::cout << "login: ";
    std::cin >> input;
    contact->setLogin(input);
    std::cout << "postal address: ";
    std::cin >> input;
    contact->setPostalAddress(input);
    std::cout << "email address: ";
    std::cin >> input;
    contact->setEmailAddress(input);
    std::cout << "phone number: ";
    std::cin >> input;
    contact->setPhoneNumber(input);
    std::cout << "birthday date: ";
    std::cin >> input;
    contact->setBirthdayDate(input);
    std::cout << "favorite meal: ";
    std::cin >> input;
    contact->setFavoriteMeal(input);
    std::cout << "underwear color: ";
    std::cin >> input;
    contact->setUnderwearColor(input);
    std::cout << "darkest secret: ";
    std::cin >> input;
    contact->setDarkestSecret(input);
    this->index++;
    std::cout << "+++++ Contact has been added to Phonebook +++++" << std::endl;
    return ;
}

int         PhoneBook::getIndex(void)
{
    return (this->index);
}
