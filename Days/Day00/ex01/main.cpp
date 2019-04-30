/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:20:01 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/30 15:49:01 by jcasian          ###   ########.fr       */
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
		std::getline(std::cin, input);
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