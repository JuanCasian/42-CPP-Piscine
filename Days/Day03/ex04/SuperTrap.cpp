/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:54:45 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/03 16:09:09 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) {
	return ;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(100, 100, 120, 120, 1,
name, 60, 20, 55, 11, 99, 2, 13, 5, "SUP3R-TP"), NinjaTrap(), FragTrap() {
	std::cout << "SuperTrap constructor called" << std::endl;
	return ;
}

SuperTrap::SuperTrap(SuperTrap const &src) {
	std::cout << "SuperTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}
SuperTrap::~SuperTrap(void) {
	std::cout << "SuperTrap destructor called" << std::endl;
	return ;
}

/* Operators overload */
SuperTrap	&SuperTrap::operator=(SuperTrap const &rhs) {
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

