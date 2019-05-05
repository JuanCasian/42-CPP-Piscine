/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:38:22 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 18:44:34 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

/* Constructors */
AWeapon::AWeapon(void) {
	return ;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
_name(name), _APCost(apcost), _damage(damage) {
	return ;
}

AWeapon::AWeapon(AWeapon const &src) {
	*this = src;
	return;
}

/* Destructor */
AWeapon::~AWeapon(void) {
	return ;
}

/* Operator */
AWeapon	&AWeapon::operator=(AWeapon const &rhs) {
	this->_APCost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	this->_name = rhs.getName();
	return *this;
}

/* Getters and setters */
std::string AWeapon::getName(void) const {
	return this->_name;
}
int AWeapon::getAPCost(void) const {
	return this->_APCost;
}
int AWeapon::getDamage(void) const {
	return this->_damage;
}

/* Other */
