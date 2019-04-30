/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:34:06 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/30 16:05:09 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crappy_phonebook.hpp"

Phonebook::Phonebook(void){
	this->_nb_contacts = 0;
	return ;
}

Phonebook::~Phonebook(void){
	return ;
}

void Phonebook::add_contact(void) {
	Contact new_contact;

	if (this->_nb_contacts >= 8)
	{
		std::cout << "The contact list is full, please try another command." << std::endl;
		return ;
	}
	std::cout << "You chose to add a contact, please fill the next fields" << std::endl;
	new_contact.set_first_name();
	new_contact.set_last_name();
	new_contact.set_nickname();
	new_contact.set_login();
	new_contact.set_postal_address();
	new_contact.set_email_address();
	new_contact.set_phone_number();
	new_contact.set_birthday_date();
	new_contact.set_favorite_meal();
	new_contact.set_underwear_color();
	new_contact.set_darkest_secret();
	this->_contacts[this->_nb_contacts] = new_contact;
	this->_nb_contacts += 1;
	std::cout << "Contact added!" << std::endl;
}

void Phonebook::search_contact(void) const{
	int i;
	std::string input;

	if (this->_nb_contacts <= 0)
	{
		std::cout << "There are no contacts saved, please add some." << std::endl;
		return ;
	}
	std::cout << "Here is a list of all the contacts saved:" << std::endl;
	std::cout << "|  Index   |First Name|Last  Name| Nickname |" << std::endl;
	i = -1;
	while (++i < this->_nb_contacts)
		this->_contacts[i].print_preview(i);
	std::cout << std::endl << "Please insert the index: ";
	std::getline(std::cin, input);
	try {
		i = std::stoi(input);
	} catch(...) {
		std::cout << "There is a an error with your input, returning to main menu" << std::endl;
		return ;
	}
	if (i < 0 || i > 7)
		std::cout << "The number entered is not valid, going back to main menu." << std::endl;
	else
	{
		if (i >= this->_nb_contacts)
		{
			std::cout << "Contact you chose is not added yet, going back to menu" << std::endl;
			return ;
		}
		this->_contacts[i].print_contact();
		std::cout << "Contact information printed, going back to menu" << std::endl;
	}
}