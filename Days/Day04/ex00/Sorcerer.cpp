/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:48:27 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 16:27:44 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

/* Constructors */
Sorcerer::Sorcerer(void) {
	return ;
}

Sorcerer::Sorcerer(std::string name, std::string title) : 
_name(name), _title(title) {
	std::cout << name << ", " << title << ", is born !" << std::endl;
	return ;
}

Sorcerer::Sorcerer(Sorcerer const &src) {
	*this = src;
	return;
}

/* Destructor */
Sorcerer::~Sorcerer(void) {
	std::cout << this->_name << ", " << this->_title << ", is dead. ";
	std::cout << "Consequences will never be the same !" << std::endl;
	return ;
}

/* Operator */
Sorcerer	&Sorcerer::operator=(Sorcerer const &rhs) {
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Sorcerer const &rhs) {
	o << "I am " << rhs.getName() << ", " << rhs.getTitle();
	o << ", and I like ponies !" << std::endl;
	return o;
}

/* getter and setters */
std::string	Sorcerer::getName(void) const {
	return this->_name;
}
void	Sorcerer::setName(std::string name) {
	this->_name = name;
}

std::string	Sorcerer::getTitle(void) const {
	return this->_title;
}
void	Sorcerer::setTitle(std::string title) {
	this->_title = title;
}

/* Other */
void	Sorcerer::polymorph(Victim const &victim) const {
	victim.getPolymorphed();
}