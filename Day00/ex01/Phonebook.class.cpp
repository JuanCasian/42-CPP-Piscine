/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:53:10 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 19:52:46 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Phonebook.class.hpp"

Phonebook::Phonebook(void)
{
	int i;

	i = -1;
	while (++i < 8)
		this->contacts[i] = "";
	this->contacts_added = 0;
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void	Phonebook::add_contact(void)
{
	std::string	contact;
	
	if (this->contacts_added < 8)
	{
		std::cout << "Please insert the contact information: " << std::endl;
		std::getline (std::cin, contact);
		this->contacts[this->contacts_added] = contact;
		this->contacts_added += 1;
		std::cout << "Contact saved!" << std::endl << std::endl;
	}
	else
		std::cout << "The contact list is full" << std::endl << std::endl;
}

void	Phonebook::search_contact(void) const
{
	int		i;
	std::string	search_param;

	i = -1;
	std::cout << "Please insert search parameter: ";
	std::getline (std::cin, search_param);
	while (++i < this->contacts_added)
	{
		if (this->contacts[i].find(search_param) != std::string::npos)
		{
			std::cout << "Contact found, information:" << std::endl;
			std::cout << this->contacts[i] << std::endl << std::endl;
			return ;
		}
	}
	std::cout << "Contact not found" << std::endl << std::endl;
}
