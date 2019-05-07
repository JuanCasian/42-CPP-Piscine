/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EBullet.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:00:50 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 21:41:01 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EBullet.hpp"

/* Constructors */
EBullet::EBullet(void) {
    return ;
}

EBullet::EBullet(int x, int y) : CanvasObj(x, y, '-') {
    return ;
}

EBullet::EBullet(EBullet const &src) {
    *this = src;
    return ;
}

/* Destructor */
EBullet::~EBullet(void) {
    return ;
}

/* Operator */
EBullet	&EBullet::operator=(EBullet const &rhs) {
    this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_c = rhs.getC();
	this->_next = rhs.getNext();
	this->_prev = rhs.getPrev();
    return *this;
}

/* Other */
int		EBullet::move(WINDOW *win, int x, int y, int minx, int  miny, int maxx, int maxy) {
	x = 0;
	y = 0;
    mvwaddch(win, this->_y, this->_x, ' ');
	this->_x -= 2;
	if (this->inside(minx, miny, maxx, maxy))
		return (1);
	return (0);
}
int		EBullet::collides(int x, int y) const {
    if (this->_y == y && (this->_x == x || this->_x + 1 == x))
		return (1);
	return (0);
}

/* Getters and Setters */
