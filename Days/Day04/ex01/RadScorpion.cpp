/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:11:55 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 19:12:58 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

/* Constructors */
RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
	return ;
}

RadScorpion::RadScorpion(RadScorpion const &src) {
	*this = src;
	return;
}

/* Destructor */
RadScorpion::~RadScorpion(void) {
	std::cout << "* SPROTCH *" << std::endl;
	return ;
}

/* Operator */
RadScorpion	&RadScorpion::operator=(RadScorpion const &rhs) {
	this->_hp = rhs.getHP();
	this->_type = rhs.getType();
	return *this;
}

/* Getters and setters */

/* Other */