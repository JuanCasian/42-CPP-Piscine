/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:32:02 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 16:37:24 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

/* Constructors */
Peon::Peon(void) {
	return ;
}

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::Peon(Peon const &src) {
	*this = src;
	return;
}

/* Destructor */
Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
	return ;
}

/* Operator */
Peon	&Peon::operator=(Peon const &rhs) {
	this->_name = rhs.getName();
	return *this;
}

/* Getters and setters */

/* Other */
void	Peon::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}