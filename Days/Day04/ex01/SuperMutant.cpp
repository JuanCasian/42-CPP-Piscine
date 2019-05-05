/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:04:05 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 19:09:40 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

/* Constructors */
SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return ;
}

SuperMutant::SuperMutant(SuperMutant const &src) {
	*this = src;
	return;
}

/* Destructor */
SuperMutant::~SuperMutant(void) {
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

/* Operator */
SuperMutant	&SuperMutant::operator=(SuperMutant const &rhs) {
	this->_hp = rhs.getHP();
	this->_type = rhs.getType();
	return *this;
}

/* Getters and setters */

/* Other */
void	SuperMutant::takeDamage(int damage) {
	if (damage - 3 < 0)
		return ;
	if (this->_hp - damage + 3 < 0) {
		this->_hp = 0;
	} else {
		this->_hp -= damage + 3;
	}
}