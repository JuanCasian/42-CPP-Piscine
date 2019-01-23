/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:19:37 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 20:19:39 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "crappy_phonebook.hpp"

Phonebook::Phonebook(void){
	this->nb_contacts = 0;
	return ;
}

Phonebook::~Phonebook(void){
	return ;
}

void Phonebook::add_contact(void) {
	Contact new_contact;

	if (this->nb_contacts >= 8)
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
	this->contacts[this->nb_contacts] = new_contact;
	this->nb_contacts += 1;
	std::cout << "Contact added!" << std::endl;
}

void Phonebook::search_contact(void) const{
	int i;

	if (this->nb_contacts <= 0)
	{
		std::cout << "There are no contacts saved, please add some." << std::endl;
		return ;
	}
	std::cout << "Here is a list of all the contacts saved:" << std::endl;
	std::cout << "|  Index   |First Name|Last  Name| Nickname |" << std::endl;
	i = -1;
	while (++i < this->nb_contacts)
		this->contacts[i].print_preview(i);
	std::cout << std::endl << "Please insert the index: ";
	std::cin >> i;
	if (i < 0 || i > 7)
		std::cout << "The number entered is not valid, going back to main menu." << std::endl;
	else
	{
		this->contacts[i].print_contact();
		std::cout << "Contact information printed, going back to menu" << std::endl;
	}
}
