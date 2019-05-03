/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:32:10 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/03 14:02:07 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* Constructors & Destructors */
ScavTrap::ScavTrap(void) {
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(100, 100, 50, 50, 1,
 name, 20, 15, 3, 45, 14, 6, 23, 3, "SCRAV") {
		std::cout << "ScavTrap constructor called" << std::endl;
		return ;
	};

ScavTrap::ScavTrap(ScavTrap const &src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

/* Operators overload */
ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {
	this->_hitPoints = rhs.getHitPoints();
	this->_maxHitPoints = rhs.getMaxHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
	this->_level = rhs.getLevel();
	this->_name = rhs.getName();
	this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
	this->_rangedAttackDamage = rhs.getArmorDamageReduction();
	this->_fartAttackDamage = rhs.getFartAttackDamage();
	this->_danceAttackDamage = rhs.getDanceAttackDamage();
	this->_peanutButterAttackDamage = rhs.getPeanutButterAttackDamage();
	this->_bubblesAttackDamage = rhs.getBubblesAttackDamage();
	this->_ticklesAttackDamage = rhs.getTicklesAttackDamage();
	this->_armorDamageReduction = rhs.getArmorDamageReduction();
	this->_type = rhs.getType();
	return *this;
}

//Challenges

void	ScavTrap::challengeNewComer(void) const {
	srand(clock());
	std::cout << this->_challenges[rand() % this->_nChallenges] << std::endl;
}

std::string const	ScavTrap::_challenges[] = {
	"Put up or shut up!" , "Step up!", "Bring it on!",
	"Care to step outside?" , "Wanna piece of me?" ,
	"Let's go, pal!" , "Just me and you, later, buddy!",
	"¡¿Un tiro o qué?!"
};

int const			ScavTrap::_nChallenges = 8;
