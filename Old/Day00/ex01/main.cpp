/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:19:32 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 20:19:33 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crappy_phonebook.hpp"

int		main(void){
	std::string input;
	Phonebook 	pb;

	std::cout << "Welcome to a crappy phonebook." << std::endl;
	while (1)
	{
		std::cout << "Please insert a command (ADD, SEARCH, EXIT):";
		std::cin >> input;
		if (!(input.compare("SEARCH")))
			pb.search_contact();
		else if (!(input.compare("ADD")))
			pb.add_contact();
		else if (!(input.compare("EXIT")))
			break ;
		else
			std::cout << "Command not recognized, try again..." << std::endl;
	}
}
