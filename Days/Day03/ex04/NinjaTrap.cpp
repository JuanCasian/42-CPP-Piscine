/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:59:01 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/03 16:01:50 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

/* Constructors & Destructors */
NinjaTrap::NinjaTrap(void) {
	std::cout << "NinjaTrap constructor called" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(60, 60, 120, 120, 1,
name, 60, 5, 55, 11, 99, 2, 13, 0, "NINJ4-TP") {
		std::cout << "NinjaTrap constructor called" << std::endl;
		return ;
	};

NinjaTrap::NinjaTrap(NinjaTrap const &src) {
	std::cout << "NinjaTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << "NinjaTrap destructor called" << std::endl;
	return ;
}

/* Operators overload */
NinjaTrap	&NinjaTrap::operator=(NinjaTrap const &rhs) {
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

//Attacks

void	NinjaTrap::ninjaShoebox(FragTrap const &ct) const {
	std::cout << this->_type << " "  << this->_name << " throws his sable to ";
	std::cout << ct.getType() << " " << ct.getName() << std::endl; 
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const &ct) const {
	std::cout << this->_type << " "  << this->_name << " has an epic ninja fight against ";
	std::cout << ct.getType() << " " << ct.getName() << std::endl; 
}

void	NinjaTrap::ninjaShoebox(ScavTrap const &ct) const {
	std::cout << this->_type << " "  << this->_name << " throws his ninja stars to ";
	std::cout << ct.getType() << " " << ct.getName() << std::endl; 
}
