/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:50:27 by gipark            #+#    #+#             */
/*   Updated: 2021/05/12 03:15:27 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class           Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string login;
    std::string postalAddress;
    std::string emailAddress;
    std::string phoneNumber;
    std::string birthdayDate;
    std::string favoriteMeal;
    std::string underwearColor;
    std::string darkestSecret;

public:
    virtual     ~Contact();
    void        display_list(void);
    void        display_info(void);
    void        setFirstName(std::string str);
    void        setLastName(std::string str);
    void        setNickname(std::string str);
    void        setLogin(std::string str);
    void        setPostalAddress(std::string str);
    void        setEmailAddress(std::string str);
    void        setPhoneNumber(std::string str);
    void        setBirthdayDate(std::string str);
    void        setFavoriteMeal(std::string str);
    void        setUnderwearColor(std::string str);
    void        setDarkestSecret(std::string str);
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getLogin();
    std::string getPostalAddress();
    std::string getEmailAddress();
    std::string getPhoneNumber();
    std::string getBirthdayDate();
    std::string getFavoriteMeal();
    std::string getUnderwearColor();
    std::string getDarkestSecret();
};

#endif
