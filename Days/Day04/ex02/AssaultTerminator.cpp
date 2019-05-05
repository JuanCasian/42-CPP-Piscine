/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:45:30 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 22:10:00 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

/* Constructors */
AssaultTerminator::AssaultTerminator(void) {
	std::cout << "* teleports from space *" << std::endl;
	return ;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &src) {
	std::cout << "* teleports from space *" << std::endl;
	*this = src;
	return;
}

/* Destructor */
AssaultTerminator::~AssaultTerminator(void) {
	std::cout << "I'll be back ..." << std::endl;
	return ;
}

/* Operator */
AssaultTerminator	&AssaultTerminator::operator=(AssaultTerminator const &) {
	return *this;
}

/* Getters and setters */

/* Other */
void 	AssaultTerminator::battleCry(void) const {
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}
void 	AssaultTerminator::rangedAttack(void) const {
	std::cout << "* does nothing *" << std::endl;
}
void 	AssaultTerminator::meleeAttack(void) const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

ISpaceMarine	*AssaultTerminator::clone(void) const {
	ISpaceMarine *tmp = new AssaultTerminator();
	return tmp;
}