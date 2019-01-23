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

#include "crappy_phonebook.hpp"

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

std::string	Contact::format_manager(std::string str) const{
	size_t	len;

	len = str.length();
	if (len >= 10)
		return (str.substr(0, 9) + ".");
	else
	{
		while (len++ < 10)
		{
			str = " " + str;
		}
	}
	return (str);
}

void 	Contact::print_preview(int index) const{
    std::cout << "|" << this->format_manager(std::to_string(index)) << "|";
	std::cout << this->format_manager(this->first_name) << "|";
	std::cout << this->format_manager(this->last_name) << "|";
	std::cout << this->format_manager(this->nickname) << "|" << std::endl;
}

void 	Contact::print_contact(void) const{
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

std::string 	Contact::get_first_name(void) const{
    return this->first_name;
}

std::string 	Contact::get_last_name(void) const{
    return this->last_name;
}

std::string 	Contact::get_nickname(void) const{
    return this->nickname;
}

std::string 	Contact::get_login(void) const{
    return this->login;
}

std::string 	Contact::get_postal_address(void) const{
    return this->postal_address;
}

std::string 	Contact::get_email_address(void) const{
    return this->email_address;
}

std::string 	Contact::get_phone_number(void) const{
    return this->phone_number;
}

std::string 	Contact::get_birthday_date(void) const{
    return this->birthday_date;
}

std::string 	Contact::get_favorite_meal(void) const{
    return this->favorite_meal;
}

std::string 	Contact::get_underwear_color(void) const{
    return this->underwear_color;
}

std::string 	Contact::get_darkest_secret(void) const{
    return this->darkest_secret;
}

void 	Contact::set_first_name(void) {
    std::string info;
    std::cout << "Please insert first name:" << std::endl;
    std::cin >> info;
    this->first_name = info;
}

void 	Contact::set_last_name(void) {
    std::string info;
    std::cout << "Please insert last name:" << std::endl;
    std::cin >> info;
    this->last_name = info;
}

void 	Contact::set_nickname(void) {
    std::string info;
    std::cout << "Please insert nickname:" << std::endl;
    std::cin >> info;
    this->nickname = info;
}

void 	Contact::set_login(void) {
    std::string info;
    std::cout << "Please insert login:" << std::endl;
    std::cin >> info;
    this->login = info;
}

void 	Contact::set_postal_address(void) {
    std::string info;
    std::cout << "Please insert postal address:" << std::endl;
    std::cin >> info;
    this->postal_address = info;
}

void 	Contact::set_email_address(void) {
    std::string info;
    std::cout << "Please insert email email address:" << std::endl;
    std::cin >> info;
    this->email_address = info;
}

void 	Contact::set_phone_number(void) {
    std::string info;
    std::cout << "Please insert phone number:" << std::endl;
    std::cin >> info;
    this->phone_number = info;
}

void 	Contact::set_birthday_date(void) {
    std::string info;
    std::cout << "Please insert birthday date:" << std::endl;
    std::cin >> info;
    this->birthday_date = info;
}

void 	Contact::set_favorite_meal(void) {
    std::string info;
    std::cout << "Please insert favorite meal:" << std::endl;
    std::cin >> info;
    this->favorite_meal = info;
}

void 	Contact::set_underwear_color(void) {
    std::string info;
    std::cout << "Please insert underwear color:" << std::endl;
    std::cin >> info;
    this->underwear_color = info;
}

void 	Contact::set_darkest_secret(void) {
    std::string info;
    std::cout << "Please insert darkest secret:" << std::endl;
    std::cin >> info;
    this->darkest_secret = info;
}
