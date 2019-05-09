/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:54:39 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/08 22:54:47 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

/* Constructors */
C::C(void) {
	return ;
}

C::C(C const &src) {
	*this = src;
	return ;
}

/* Destructor */
C::~C(void) {
	return ;
}

/* Operator */
C	&C::operator=(C const &) {
	return *this;
}

/* Getters and Setters */
