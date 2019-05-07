/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:49:19 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 21:41:30 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

/* Constructors */
Enemy::Enemy(void) {
    return ;
}

Enemy::Enemy(int x, int y) : CanvasObj(x, y, '@') {
    return ;
}

Enemy::Enemy(Enemy const &src) {
    *this = src;
    return ;
}

/* Destructor */
Enemy::~Enemy(void) {
    return ;
}

/* Operator */
Enemy	&Enemy::operator=(Enemy const &rhs) {
    this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_c = rhs.getC();
	this->_next = rhs.getNext();
	this->_prev = rhs.getPrev();
    return *this;
}

/* Other */
int		Enemy::move(WINDOW *win, int x, int y, int minx, int  miny, int maxx, int maxy) {
    x = 0;
    y = 0;
    mvwaddch(win, this->_y, this->_x, ' ');
	this->_x -= 1;
	if (this->inside(minx, miny, maxx, maxy))
		return (1);
	return (0);
}

/* Getters and Setters */
