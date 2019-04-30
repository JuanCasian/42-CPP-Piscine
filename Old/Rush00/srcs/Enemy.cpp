/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:34:47 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/27 15:35:01 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Enemy.hpp"

/* Constructors */
Enemy::Enemy(void) {
    return ;
}

Enemy::Enemy(int posx, int posy, WINDOW *win) {
    this->_posx = posx;
    this->_posy = posy;
    this->_win = win;
    return ;
}

Enemy::Enemy(Enemy const & src) {
    *this = src;
    return ;
}

/* Destructor */
Enemy::~Enemy(void) {
    return ;
}

/* Operator */
Enemy &     Enemy::operator=(Enemy const & rhs) {
    if (this != &rhs) {
        this->_posx = getPosx();
        this->_posy = getPosy();
        this->_win = getWin();
    }
    return *this;
}

void   Enemy::move(void) {
    mvwaddch(this->_win, this->_posy, this->_posx, ' ');
    this->_posx -= 1;
}

void   Enemy::display(void) const {
    mvwaddch(this->_win, this->_posy, this->_posx, '@');
}

/* getters and setters */
int    Enemy::getPosx(void) const{
    return this->_posx;
}

void   Enemy::setPosx(int posx) {
    this->_posx = posx;
}

int    Enemy::getPosy(void) const{
    return this->_posy;
}

void   Enemy::setPosy(int posy) {
    this->_posy = posy;
}

WINDOW*    Enemy::getWin(void) const{
    return this->_win;
}

void   Enemy::setWin(WINDOW* win) {
    this->_win = win;
}
