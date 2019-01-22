/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:22:02 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 19:50:02 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"
#include <iostream>
#include <string>

int		main(void)
{
	Phonebook	pb;
	std::string	input;
	while (1)
	{
		std::cout << "Please insert a command: (ADD, SEARCH, EXIT)" << std::endl;
		std::getline (std::cin, input);
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
