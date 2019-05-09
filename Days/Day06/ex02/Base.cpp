/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:49:23 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/08 22:49:28 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/* Constructors */
Base::Base(void) {
	return ;
}

Base::Base(Base const &src) {
	*this = src;
	return ;
}

/* Destructor */
Base::~Base(void) {
	return ;
}

/* Operator */
Base	&Base::operator=(Base const &) {
	
	return *this;
}

/* Getters and Setters */
