/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:02:12 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/26 14:02:21 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Victim.hpp"

/* Constructors */
Victim::Victim(void) {
    this->_name = "DefaultName";
    std::cout << "Some random victim called " << this->_name \
    << " just popped !" << std::endl;
    return ;
}

Victim::Victim(std::string name) {
    this->_name = name;
    std::cout << "Some random victim called " << this->_name \
    << " just popped !" << std::endl;
    return ;
}

Victim::Victim(Victim const & src) {
    *this = src;
    std::cout << "Some random victim called " << this->_name \
    << " just popped !" << std::endl;
    return ;
}

/* Destructor */
Victim::~Victim(void) {
    std::cout << "Victim " << this->_name \
    << " just died for no apparent reason !" << std::endl;
    return ;
}

/* Operator */
Victim &     Victim::operator=(Victim const & rhs) {
    if (this != &rhs) {
        this->_name = rhs.getName();
    }
    return *this;
}

std::ostream &  operator<<(std::ostream &out, Victim const &rhs) {
    out << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
    return (out);
}

void            Victim::getPolymorphed(void) const {
    std::cout << this->_name << "  has been turned into a cute little sheep !" << std::endl;
}

std::string    Victim::getName(void) const{
    return this->_name;
}

void   Victim::setName(std::string name) {
    this->_name = name;
}
