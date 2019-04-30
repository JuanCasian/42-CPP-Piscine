/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:22:26 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/30 15:55:50 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crappy_phonebook.hpp"

Contact::Contact(void) : _first_name(""),
	_last_name(""),
	_nickname(""),
	_login(""),
	_postal_address(""),
	_email_address(""),
	_phone_number(""),
	_birthday_date(""),
	_favorite_meal(""),
	_underwear_color(""),
	_darkest_secret("") {
		return ;
}

Contact::~Contact(void) {
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

void 	Contact::print_preview(int index) const {
    std::cout << "|" << this->format_manager(std::to_string(index)) << "|";
	std::cout << this->format_manager(this->_first_name) << "|";
	std::cout << this->format_manager(this->_last_name) << "|";
	std::cout << this->format_manager(this->_nickname) << "|" << std::endl;
}

void 	Contact::print_contact(void) const{
    std::cout << "Printing contact information:" << std::endl;
    std::cout << "First name: " << this->_first_name << std::endl;
    std::cout << "Last name: " << this->_last_name << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Login: " << this->_login << std::endl;
    std::cout << "Postal address: " << this->_postal_address << std::endl;
    std::cout << "Email address: " << this->_email_address << std::endl;
    std::cout << "Phone number: " << this->_phone_number << std::endl;
    std::cout << "Birthday date: " << this->_birthday_date << std::endl;
    std::cout << "Favorite meal: " << this->_favorite_meal << std::endl;
    std::cout << "Underwear color: " << this->_underwear_color << std::endl;
    std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
}

void 	Contact::set_first_name(void) {
    std::string info;
    std::cout << "Please insert first name:" << std::endl;
    std::getline(std::cin, info);
    this->_first_name = info;
}

void 	Contact::set_last_name(void) {
    std::string info;
    std::cout << "Please insert last name:" << std::endl;
    std::getline(std::cin, info);
    this->_last_name = info;
}

void 	Contact::set_nickname(void) {
    std::string info;
    std::cout << "Please insert nickname:" << std::endl;
    std::getline(std::cin, info);
    this->_nickname = info;
}

void 	Contact::set_login(void) {
    std::string info;
    std::cout << "Please insert login:" << std::endl;
    std::getline(std::cin, info);
    this->_login = info;
}

void 	Contact::set_postal_address(void) {
    std::string info;
    std::cout << "Please insert postal address:" << std::endl;
    std::getline(std::cin, info);
    this->_postal_address = info;
}

void 	Contact::set_email_address(void) {
    std::string info;
    std::cout << "Please insert email email address:" << std::endl;
    std::getline(std::cin, info);
    this->_email_address = info;
}

void 	Contact::set_phone_number(void) {
    std::string info;
    std::cout << "Please insert phone number:" << std::endl;
    std::getline(std::cin, info);
    this->_phone_number = info;
}

void 	Contact::set_birthday_date(void) {
    std::string info;
    std::cout << "Please insert birthday date:" << std::endl;
    std::getline(std::cin, info);
    this->_birthday_date = info;
}

void 	Contact::set_favorite_meal(void) {
    std::string info;
    std::cout << "Please insert favorite meal:" << std::endl;
    std::getline(std::cin, info);
    this->_favorite_meal = info;
}

void 	Contact::set_underwear_color(void) {
    std::string info;
    std::cout << "Please insert underwear color:" << std::endl;
    std::getline(std::cin, info);
    this->_underwear_color = info;
}

void 	Contact::set_darkest_secret(void) {
    std::string info;
    std::cout << "Please insert darkest secret:" << std::endl;
    std::getline(std::cin, info);
    this->_darkest_secret = info;
}