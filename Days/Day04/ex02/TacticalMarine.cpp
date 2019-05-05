/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:33:11 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 22:09:05 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

/* Constructors */
TacticalMarine::TacticalMarine(void) {
	std::cout << "Tactical Marine ready for battle" << std::endl;
	return ;
}

TacticalMarine::TacticalMarine(TacticalMarine const &src) {
	std::cout << "Tactical Marine ready for battle" << std::endl;
	*this = src;
	return;
}

/* Destructor */
TacticalMarine::~TacticalMarine(void) {
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

/* Operator */
TacticalMarine	&TacticalMarine::operator=(TacticalMarine const &) {
	return *this;
}

/* Getters and setters */

/* Other */
void 	TacticalMarine::battleCry(void) const {
	std::cout << "For the holy PLOT !" << std::endl;
}
void 	TacticalMarine::rangedAttack(void) const {
	std::cout << "* attacks with bolter *" << std::endl;
}
void 	TacticalMarine::meleeAttack(void) const {
	std::cout << "* attacks with chainsword *" << std::endl;
}

ISpaceMarine	*TacticalMarine::clone(void) const {
	ISpaceMarine *tmp = new TacticalMarine();
	return tmp;
}