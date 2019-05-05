/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:56:47 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 19:02:26 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

/* Constructors */
Enemy::Enemy(void) {
	return ;
}

Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type){
	return ;
}

Enemy::Enemy(Enemy const &src) {
	*this = src;
	return;
}

/* Destructor */
Enemy::~Enemy(void) {
	return ;
}

/* Operator */
Enemy	&Enemy::operator=(Enemy const &rhs) {
	this->_hp = rhs.getHP();
	this->_type = rhs.getType();
	return *this;
}

/* Getters and setters */
int	Enemy::getHP(void) const {
	return this->_hp;
}
void	Enemy::setHP(int hp) {
	this->_hp = hp;
}

std::string	Enemy::getType(void) const {
	return this->_type;
}
void	Enemy::setType(std::string type) {
	this->_type = type;
}

/* Other */
void	Enemy::takeDamage(int damage) {
	if (damage > 0) {
		if (this->_hp - damage < 0) {
			this->_hp = 0;
		} else {
			this->_hp -= damage;
		}
	}
}
