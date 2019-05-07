/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FBullet.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:00:50 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 21:41:12 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FBullet.hpp"

/* Constructors */
FBullet::FBullet(void) {
    return ;
}

FBullet::FBullet(int x, int y) : CanvasObj(x, y, '-') {
    return ;
}

FBullet::FBullet(FBullet const &src) {
    *this = src;
    return ;
}

/* Destructor */
FBullet::~FBullet(void) {
    return ;
}

/* Operator */
FBullet	&FBullet::operator=(FBullet const &rhs) {
    this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_c = rhs.getC();
	this->_next = rhs.getNext();
	this->_prev = rhs.getPrev();
    return *this;
}

/* Other */
int		FBullet::move(WINDOW *win, int x, int y, int minx, int  miny, int maxx, int maxy) {
	x = 0;
	y = 0;
    mvwaddch(win, this->_y, this->_x, ' ');
	this->_x += 2;
	if (this->inside(minx, miny, maxx, maxy))
		return (1);
	return (0);
}
int		FBullet::collides(int x, int y) const {
    if (this->_y == y && (this->_x == x || this->_x - 1 == x))
		return (1);
	return (0);
}

/* Getters and Setters */
