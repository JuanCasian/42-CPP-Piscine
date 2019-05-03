/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:06:51 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/03 14:44:01 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constructors & Destructors */
ClapTrap::ClapTrap(int hitPoints, int maxHitPoints,
int energyPoints, int maxEnergyPoints,
int level, std::string name, int meleeAttackDamage,
int rangedAttackDamage, int fartAttackDamage,
int danceAttackDamage, int peanutButterAttackDamage,
int bubblesAttackDamage, int ticklesAttackDamage,
int armorDamageReduction,
std::string type) : _hitPoints(hitPoints), _maxHitPoints(maxHitPoints),
	_energyPoints(energyPoints), _maxEnergyPoints(maxEnergyPoints),
	_level(level), _name(name), _meleeAttackDamage(meleeAttackDamage),
	_rangedAttackDamage(rangedAttackDamage), _fartAttackDamage(fartAttackDamage), 
	_danceAttackDamage(danceAttackDamage), _peanutButterAttackDamage(peanutButterAttackDamage),
	_bubblesAttackDamage(bubblesAttackDamage), _ticklesAttackDamage(ticklesAttackDamage),
	_armorDamageReduction(armorDamageReduction),
	_type(type) {
	std::cout << "ClapTrap constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(void) {
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}


/* Operators overload */
ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs) {
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
	return *this;
}


/* Getters and Setters */
int				ClapTrap::getHitPoints(void) const {
	return this->_hitPoints;
}

int				ClapTrap::getMaxHitPoints(void) const {
	return this->_maxHitPoints;
}

int				ClapTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

int				ClapTrap::getMaxEnergyPoints(void) const {
	return this->_maxEnergyPoints;
}

int				ClapTrap::getLevel(void) const {
	return this->_level;
}

std::string		ClapTrap::getName(void) const {
	return this->_name;
}

int				ClapTrap::getMeleeAttackDamage(void) const {
	return this->_meleeAttackDamage;
}

int				ClapTrap::getRangedAttackDamage(void) const {
	return this->_rangedAttackDamage;
}

int				ClapTrap::getArmorDamageReduction(void) const {
	return this->_armorDamageReduction;
}

int				ClapTrap::getFartAttackDamage(void) const {
	return this->_fartAttackDamage;
}

int				ClapTrap::getDanceAttackDamage(void) const {
	return this->_danceAttackDamage;
}

int				ClapTrap::getPeanutButterAttackDamage(void) const {
	return this->_peanutButterAttackDamage;
}

int				ClapTrap::getBubblesAttackDamage(void) const {
	return this->_bubblesAttackDamage;
}

int				ClapTrap::getTicklesAttackDamage(void) const {
	return this->_ticklesAttackDamage;
}

std::string		ClapTrap::getType(void) const {
	return this->_type;
}

/* Other */
void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints - (int)amount + this->_armorDamageReduction < 0) {
		std::cout << this->_type << " "  << this->_name << " recieved " << this->_hitPoints;
		std::cout << " of damaged. It's current HP is 0. Basically dead!" << std::endl;
		this->_hitPoints = 0;
	} else {
		this->_hitPoints = this->_hitPoints - amount + this->_armorDamageReduction;
		std::cout << this->_type << " "  << this->_name << " recieved " << amount;
		std::cout << " of damaged. It's current HP is " << this->_hitPoints << std::endl;
	}

}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints + (int)amount >= this->_maxHitPoints) {
		std::cout << this->_type << " "  << this->_name << " healed itself ";
		std::cout << (this->_maxHitPoints - this->_hitPoints); 
		std::cout << " points. New HP: " << this->_maxHitPoints;
		std::cout <<  " Now it is fully healed. " << std::endl;
		this->_hitPoints = this->_maxHitPoints;
	} else {
		this->_hitPoints += amount;
		std::cout << this->_type << " "  << this->_name << " healed itself ";
		std::cout << amount << " points. New HP: "<< this->_hitPoints << std::endl;
	}
}

//Attacks
void	ClapTrap::rangedAttack(std::string const &target) const {
	std::cout << this->_type << " "  << this->_name << " ranged attacks " << target;
	std::cout << " causing " << this->_rangedAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ClapTrap::meleeAttack(std::string const &target) const {
	std::cout << this->_type << " "  << this->_name << " melee attacks " << target;
	std::cout << " causing " << this->_meleeAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ClapTrap::fartAttack(std::string const &target) const {
	std::cout << this->_type << " "  << this->_name << " fart attacks " << target;
	std::cout << " causing " << this->_fartAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ClapTrap::danceAttack(std::string const &target) const {
	std::cout << this->_type << " "  << this->_name << " dance attacks " << target;
	std::cout << " causing " << this->_danceAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ClapTrap::peanutButterAttack(std::string const &target) const {
	std::cout << this->_type << " "  << this->_name << " peanut butter attacks " << target;
	std::cout << " causing " << this->_peanutButterAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ClapTrap::bubblesAttack(std::string const &target) const {
	std::cout << this->_type << " "  << this->_name << " bubbles attacks " << target;
	std::cout << " causing " << this->_bubblesAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ClapTrap::ticklesAttack(std::string const &target) const {
	std::cout << this->_type << " "  << this->_name << " tickles attacks " << target;
	std::cout << " causing " << this->_ticklesAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}