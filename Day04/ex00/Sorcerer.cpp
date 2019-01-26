/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:01:53 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/26 14:02:21 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

/* Constructors */
Sorcerer::Sorcerer(void) {
    this->setName("DefautlName");
    this->setTitle("DefaultTitle");
    std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
    return ;
}

Sorcerer::Sorcerer(std::string name, std::string title) {
    this->setName(name);
    this->setTitle(title);
    std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
    return ;
}

Sorcerer::Sorcerer(Sorcerer const & src) {
    *this = src;
    std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
    return ;
}

/* Destructor */
Sorcerer::~Sorcerer(void) {
    std::cout << this->_name << ", " << this->_title \
    << ", is dead. Consequences will never be the same !" << std::endl;
    return ;
}

/* Operator */
Sorcerer &     Sorcerer::operator=(Sorcerer const & rhs) {
    if (this != &rhs) {
        this->setName(rhs.getName());
        this->setTitle(rhs.getTitle());
    }
    return *this;
}

std::ostream &  operator<<(std::ostream &out, Sorcerer const &rhs) {
    out << "I am " << rhs.getName() << ", " << rhs.getTitle() \
    << ", and I like ponies ! " << std::endl;
    return (out);
}

void            Sorcerer::polymorph(Victim const &victim) const {
    victim.getPolymorphed();
}

std::string    Sorcerer::getName(void) const{
    return this->_name;
}

void   Sorcerer::setName(std::string name) {
    this->_name = name;
}

std::string    Sorcerer::getTitle(void) const{
    return this->_title;
}

void   Sorcerer::setTitle(std::string title) {
    this->_title = title;
}
