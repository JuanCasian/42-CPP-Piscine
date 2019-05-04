/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:59:22 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 16:40:56 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

/* Constructors */
Victim::Victim(void) {
	return ;
}

Victim::Victim(std::string name) : _name(name) {
	std::cout << "Some random victim called " << name;
	std::cout << " just popped !" << std::endl;
	return ;
}

Victim::Victim(Victim const &src) {
	*this = src;
	return;
}

/* Destructor */
Victim::~Victim(void) {
	std::cout << "Victim " << this->_name;
	std::cout << " died for no apparent reason !" << std::endl;
	return ;
}

/* Operator */
Victim	&Victim::operator=(Victim const &rhs) {
	this->_name = rhs.getName();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Victim const &rhs) {
	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return o;
}

/* Getters and setters */
std::string	Victim::getName(void) const {
	return this->_name;
}
void	Victim::setName(std::string name) {
	this->_name = name;
}

/* Other */
void	Victim::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}