/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:03:54 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 23:10:38 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

/* Constructors */
Player::Player(void) {
    return ;
}

Player::Player(int x, int y) : CanvasObj(x, y, '>') {
    this->_pieces = new CanvasObjList();
    this->_pieces->push(new CanvasObj(x, y - 1, '>'));
    this->_pieces->push(new CanvasObj(x, y, '>'));
    this->_pieces->push(new CanvasObj(x + 1, y, '>'));
    this->_pieces->push(new CanvasObj(x, y + 1, '>'));
    return ;
}

Player::Player(Player const &src) {
    *this = src;
    return ;
}

/* Destructor */
Player::~Player(void) {
    delete this->_pieces;
    return ;
}

/* Operator */
Player	&Player::operator=(Player const &rhs) {
    this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_c = rhs.getC();
	this->_next = rhs.getNext();
	this->_prev = rhs.getPrev();
    this->_pieces = rhs.getPieces();
    return *this;
}

/* Other */
int     Player::collides(int x, int y) const {
    x = 0;
    return y;
}

int		Player::move(WINDOW *win, int x, int y, int minx, int  miny, int maxx, int maxy) {
    CanvasObj   *tmp;
    bool         flag;

    tmp = this->_pieces->getHead();
    flag = false;
    this->_x += x;
    this->_y += y;
    while(tmp) {
        if (!tmp->move(win, x, y, minx, miny, maxx, maxy))
            flag = true;
        tmp = tmp->getNext();
    }
    if (flag) {
        this->_x -= x;
        this->_y -= y;
        tmp = this->_pieces->getHead();
        while (tmp) {
            tmp->move(win, -x, -y, minx, miny, maxx, maxy);
            tmp = tmp->getNext();
        }
    }
    return (1);
}
int		Player::inside(int minx, int  miny, int maxx, int maxy) const {
    CanvasObj   *tmp;

    tmp = this->_pieces->getHead();
    while (tmp) {
        if (!(tmp->inside(minx, miny, maxx, maxy)))
            return (0);
        tmp = tmp->getNext();
    }
    return (1);
}
int		Player::collides(CanvasObj const *obj) const {
    CanvasObj   *tmp;

    tmp = this->_pieces->getHead();
    while (tmp) {
        if (obj->collides(tmp->getX(), tmp->getY()))
            return (1);
        tmp = tmp->getNext();
    }
    return (0);
}
void	Player::display(WINDOW *win) const {
    CanvasObj   *tmp;

    tmp = this->_pieces->getHead();
    while (tmp) {
        tmp->display(win);
        tmp = tmp->getNext();
    }
}

/* Getters and Setters */
CanvasObjList	*Player::getPieces(void) const {
    return this->_pieces;
}
void	Player::setPieces(CanvasObjList *pieces) {
    this->_pieces = pieces;
}

