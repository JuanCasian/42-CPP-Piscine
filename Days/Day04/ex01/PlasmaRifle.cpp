/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:44:55 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 19:54:00 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

/* Constructors */
PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {
	return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) {
	*this = src;
	return;
}

/* Destructor */
PlasmaRifle::~PlasmaRifle(void) {
	return ;
}

/* Operator */
PlasmaRifle	&PlasmaRifle::operator=(PlasmaRifle const &rhs) {
	this->_name = rhs.getName();
	this->_APCost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return *this;
}

/* Getters and setters */

/* Other */
void 	PlasmaRifle::attack(void) const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}