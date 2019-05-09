/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:50:21 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/08 22:50:30 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

/* Constructors */
A::A(void) {
	return ;
}

A::A(A const &src) {
	*this = src;
	return ;
}

/* Destructor */
A::~A(void) {
	return ;
}

/* Operator */
A	&A::operator=(A const &) {
	return *this;
}

/* Getters and Setters */
