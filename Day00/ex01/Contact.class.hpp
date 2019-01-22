/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:19:25 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 20:19:26 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact {
public:
    Contact(void);
    ~Contact(void);
    void print_contact(void);
    void get_first_name(void);
    void get_last_name(void);
    void get_nickname(void);
    void get_login(void);
    void get_postal_address(void);
    void get_email_address(void);
    void get_phone_number(void);
    void get_birthday_date(void);
    void get_favorite_meal(void);
    void get_underwear_color(void);
    void get_darkest_secret(void);
    void set_first_name(void);
    void set_last_name(void);
    void set_nickname(void);
    void set_login(void);
    void set_postal_address(void);
    void set_email_address(void);
    void set_phone_number(void);
    void set_birthday_date(void);
    void set_favorite_meal(void);
    void set_underwear_color(void);
    void set_darkest_secret(void);
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string login;
    std::string postal_address;
    std::string email_address;
    std::string phone_number;
    std::string birthday_date;
    std::string favorite_meal;
    std::string underwear_color;
    std::string darkest_secret;
};
