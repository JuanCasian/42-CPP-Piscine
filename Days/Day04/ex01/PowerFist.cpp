/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:50:30 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 19:53:56 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

/* Constructors */
PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {
	return ;
}

PowerFist::PowerFist(PowerFist const &src) {
	*this = src;
	return;
}

/* Destructor */
PowerFist::~PowerFist(void) {
	return ;
}

/* Operator */
PowerFist	&PowerFist::operator=(PowerFist const &rhs) {
	this->_name = rhs.getName();
	this->_APCost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return *this;
}

/* Getters and setters */

/* Other */
void 	PowerFist::attack(void) const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}