/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:19:12 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 20:19:13 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.class.cpp"

void print_preview(int index) {
    index, first name, last name and nickname.
    cout <<
}

Contact::Contact(void){
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->login = "";
    this->postal_address = "";
    this->email_address = "";
    this->phone_number = "";
    this->birthday_date = "";
    this->favorite_meal = "";
    this->underwear_color = "";
    this->darkest_secret = "";
    return ;
}

Contact::~Contact(void){
    return ;
}

void Contact::print_contact(void) {
    std::cout << "Printing contact information:" << std::endl;
    std::cout << "First name: " << this->get_first_name() << std::endl;
    std::cout << "Last name: " << this->get_last_name() << std::endl;
    std::cout << "Nickname: " << this->get_nickname() << std::endl;
    std::cout << "Login: " << this->get_login() << std::endl;
    std::cout << "Postal address: " << this->get_postal_address() << std::endl;
    std::cout << "Email address: " << this->get_email_address() << std::endl;
    std::cout << "Phone number: " << this->get_phone_number() << std::endl;
    std::cout << "Birthday date: " << this->get_birthday_date() << std::endl;
    std::cout << "Favorite meal: " << this->get_favorite_meal() << std::endl;
    std::cout << "Underwear color: " << this->get_underwear_color() << std::endl;
    std::cout << "Darkest secret: " << this->get_darkest_secret() << std::endl;
}

void Contact::get_first_name(void) {
    return this->first_name;
}

void Contact::get_last_name(void) {
    return this->last_name;
}

void Contact::get_nickname(void) {
    return this->nickname;
}

void Contact::get_login(void) {
    return this->login;
}

void Contact::get_postal_address(void) {
    return this->postal_address;
}

void Contact::get_email_address(void) {
    return this->email_address;
}

void Contact::get_phone_number(void) {
    return this->phone_number;
}

void Contact::get_birthday_date(void) {
    return this->birthday_date;
}

void Contact::get_favorite_meal(void) {
    return this->favorite_meal;
}

void Contact::get_underwear_color(void) {
    return this->underwear_color;
}

void Contact::get_darkest_secret(void) {
    return this->darkest_secret;
}

void Contact::set_first_name(void) {
    std::string info;
    std::cout << "Please insert first name:" << std::endl;
    std::getline (std::cin, info);
    this->first_name = info;
}

void Contact::set_last_name(void) {
    std::string info;
    std::cout << "Please insert last name:" << std::endl;
    std::getline (std::cin, info);
    this->last_name = info;
}

void Contact::set_nickname(void) {
    std::string info;
    std::cout << "Please insert nickname:" << std::endl;
    std::getline (std::cin, info);
    this->nickname = info;
}

void Contact::set_login(void) {
    std::string info;
    std::cout << "Please insert login:" << std::endl;
    std::getline (std::cin, info);
    this->login = info;
}

void Contact::set_postal_address(void) {
    std::string info;
    std::cout << "Please insert postal address:" << std::endl;
    std::getline (std::cin, info);
    this->postal_address = info;
}

void Contact::set_email_address(void) {
    std::string info;
    std::cout << "Please insert email email address:" << std::endl;
    std::getline (std::cin, info);
    this->email_address = info;
}

void Contact::set_phone_number(void) {
    std::string info;
    std::cout << "Please insert phone number:" << std::endl;
    std::getline (std::cin, info);
    this->phone_number = info;
}

void Contact::set_birthday_date(void) {
    std::string info;
    std::cout << "Please insert birthday date:" << std::endl;
    std::getline (std::cin, info);
    this->birthday_date = info;
}

void Contact::set_favorite_meal(void) {
    std::string info;
    std::cout << "Please insert favorite meal:" << std::endl;
    std::getline (std::cin, info);
    this->favorite_meal = info;
}

void Contact::set_underwear_color(void) {
    std::string info;
    std::cout << "Please insert underwear color:" << std::endl;
    std::getline (std::cin, info);
    this->underwear_color = info;
}

void Contact::set_darkest_secret(void) {
    std::string info;
    std::cout << "Please insert darkest secret:" << std::endl;
    std::getline (std::cin, info);
    this->darkest_secret = info;
}
