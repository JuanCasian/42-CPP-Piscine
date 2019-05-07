/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanvasObj.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:21:29 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 19:13:21 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CanvasObj.hpp"

/* Constructors */
CanvasObj::CanvasObj(void) : _x(-1), _y(-1), _c('\0'), _next(NULL),
	_prev(NULL) {
	return ;
}

CanvasObj::CanvasObj(int x, int y, char c) : _x(x),
_y(y), _c(c), _next(NULL), _prev(NULL) {
	return ;
}

CanvasObj::CanvasObj(CanvasObj const &src) {
	*this = src;
	return ;
}

/* Destructor */
CanvasObj::~CanvasObj(void) {
	this->_next = NULL;
	this->_prev = NULL;
	return ;
}


/* Operator */
CanvasObj	&CanvasObj::operator=(CanvasObj const &rhs) {
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_c = rhs.getC();
	this->_next = rhs.getNext();
	this->_prev = rhs.getPrev();
	return *this;
}

/* Other */
void			CanvasObj::display(WINDOW *win) const {
	mvwaddch(win, this->_y, this->_x, this->_c);
}

int		CanvasObj::move(WINDOW *win, int x, int y, int minx, int  miny, int maxx, int maxy) {
	mvwaddch(win, this->_y, this->_x, ' ');
	this->_x += x;
	this->_y += y;
	if (this->inside(minx, miny, maxx, maxy))
		return (1);
	return (0);
}

int		CanvasObj::inside(int minx, int miny, int maxx, int maxy) const {
	if (this->_x <= minx || this->_x  >= maxx - 1 ||
		this->_y <= miny || this->_y >= maxy - 1)
		return (0);
	return (1);
}

int		CanvasObj::collides(int x, int y) const {
	if (this->_x == x && this->_y == y)
		return (1);
	return (0);
}

/* Getters and setters */
int	CanvasObj::getX(void) const {
	return this->_x;
}
void	CanvasObj::setX(int x) {
	this->_x = x;
}

int	CanvasObj::getY(void) const {
	return this->_y;
}
void	CanvasObj::setY(int y) {
	this->_y = y;
}

char	CanvasObj::getC(void) const {
	return this->_c;
}
void	CanvasObj::setC(char c) {
	this->_c = c;
}

CanvasObj	*CanvasObj::getNext(void) const {
	return this->_next;
}
void	CanvasObj::setNext(CanvasObj *next) {
	this->_next = next;
}

CanvasObj	*CanvasObj::getPrev(void) const {
	return this->_prev;
}
void	CanvasObj::setPrev(CanvasObj *prev) {
	this->_prev = prev;
}
