/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:53:52 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/08 22:53:53 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

/* Constructors */
B::B(void) {
	return ;
}

B::B(B const &src) {
	*this = src;
	return ;
}

/* Destructor */
B::~B(void) {
	return ;
}

/* Operator */
B	&B::operator=(B const &) {
	return *this;
}

/* Getters and Setters */
