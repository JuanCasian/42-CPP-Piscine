/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:16:49 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/02 17:01:03 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* Constructors & Destructors */
FragTrap::FragTrap(void) {
	return ;
}

FragTrap::FragTrap(std::string name) : _hitPoints(100), _maxHitPoints(100),
	_energyPoints(100), _maxEnergyPoints(100),
	_level(1), _name(name), _meleeAttackDamage(30),
	_rangedAttackDamage(20), _armorDamageReduction(5) {
		std::cout << "Fragtrap constructor called" << std::endl;
		return ;
	};

FragTrap::FragTrap(FragTrap const &src) {
	std::cout << "Fragtrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout << "Fragtrap destructor called" << std::endl;
	return ;
}

/* Operators overload */
FragTrap	&FragTrap::operator=(FragTrap const &rhs) {
	this->_hitPoints = getHitPoints();
	this->_maxHitPoints = getMaxHitPoints();
	this->_energyPoints = getEnergyPoints();
	this->_maxEnergyPoints = getMaxEnergyPoints();
	this->_level = getLevel();
	this->_name = getName();
	this->_meleeAttackDamage = getMeleeAttackDamage();
	this->_rangedAttackDamage = getArmorDamageReduction();
	this->_armorDamageReduction = getArmorDamageReduction();
	return ;
}

/* Getters and Setters */
int				FragTrap::getHitPoints(void) const {
	return this->_hitPoints;
}

int				FragTrap::getMaxHitPoints(void) const {
	return this->_maxHitPoints;
}

int				FragTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

int				FragTrap::getMaxEnergyPoints(void) const {
	return this->_maxEnergyPoints;
}

int				FragTrap::getLevel(void) const {
	return this->_level;
}

std::string		FragTrap::getName(void) const {
	return this->_name;
}

int				FragTrap::getMeleeAttackDamage(void) const {
	return this->_meleeAttackDamage;
}

int				FragTrap::getRangedAttackDamage(void) const {
	return this->_rangedAttackDamage;
}

int				FragTrap::getArmorDamageReduction(void) const {
	return this->_armorDamageReduction;
}

/* Other */
void	FragTrap::rangedAttack(std::string const &target) {
	std::cout << "FR4g-TP " << this->_name << " attacks " << target;
	std::cout << " causing " << this->_rangedAttackDamage << "points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	FragTrap::meleeAttack(std::string const &target) {
	std::cout << "FR4g-TP " << this->_name << " attacks " << target;
	std::cout << " causing " << this->_meleeAttackDamage << "points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints - amount + this->_armorDamageReduction < 0) {
		std::cout << "FR4G-TP " << this->_name << " recieved " << this->_hitPoints;
		std::cout << " of damaged. It's current HP is 0. Basically dead!" << std::endl;
		this->_hitPoints = 0;
	} else {
		this->_hitPoints = this->_hitPoints - amount + this->_armorDamageReduction;
		std::cout << "FR4G-TP " << this->_name << " recieved " << amount;
		std::cout << " of damaged. It's current HP is " << this->_hitPoints << std::endl;
	}

}

void	FragTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints + amount >= this->_maxHitPoints) {
		std::cout << "FR4G-TP " << this->_name << " healed itself ";
		std::cout << (this->_maxHitPoints - this->_hitPoints); 
		std::cout << " points. New HP: " << this->_maxHitPoints;
		std::cout <<  " Now it is fully healed. " << std::endl;
		this->_hitPoints = this->_maxHitPoints;
	} else {
		this->_hitPoints += amount;
		std::cout << "FR4G-TP " << this->_name << " healed itself ";
		std::cout << amount << " points. New HP: "<< this->_hitPoints << std::endl;
	}
}
