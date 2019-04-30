/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:02:00 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/26 14:02:21 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

/* Constructors */
Peon::Peon(void) {
    this->setName("Default");
    std::cout << "Zog zog." << std::endl;
    return ;
}

Peon::Peon(std::string name) : Victim(name) {
    this->setName(name);
    std::cout << "Zog zog." << std::endl;
    return ;
}

Peon::Peon(Peon const & src) {
    *this = src;
    std::cout << "Zog zog." << std::endl;
    return ;
}

/* Destructor */
Peon::~Peon(void) {
    std::cout << "Bleuark..." << std::endl;
    return ;
}

/* Operator */
Peon &     Peon::operator=(Peon const & rhs) {
    if (this != &rhs) {
        this->setName(rhs.getName());
    }
    return *this;
}

void       Peon::getPolymorphed(void) const {
    std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}
