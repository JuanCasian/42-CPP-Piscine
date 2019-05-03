/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:32:10 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/02 20:51:37 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* Constructors & Destructors */
ScavTrap::ScavTrap(void) {
	return ;
}

ScavTrap::ScavTrap(std::string name) : _hitPoints(100), _maxHitPoints(100),
	_energyPoints(50), _maxEnergyPoints(50),
	_level(1), _name(name), _meleeAttackDamage(20),
	_rangedAttackDamage(15), _fartAttackDamage(3), 
	_danceAttackDamage(45), _peanutButterAttackDamage(14),
	_bubblesAttackDamage(6), _ticklesAttackDamage(23),
	_armorDamageReduction(3) {
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
	return *this;
}

/* Getters and Setters */
int				ScavTrap::getHitPoints(void) const {
	return this->_hitPoints;
}

int				ScavTrap::getMaxHitPoints(void) const {
	return this->_maxHitPoints;
}

int				ScavTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

int				ScavTrap::getMaxEnergyPoints(void) const {
	return this->_maxEnergyPoints;
}

int				ScavTrap::getLevel(void) const {
	return this->_level;
}

std::string		ScavTrap::getName(void) const {
	return this->_name;
}

int				ScavTrap::getMeleeAttackDamage(void) const {
	return this->_meleeAttackDamage;
}

int				ScavTrap::getRangedAttackDamage(void) const {
	return this->_rangedAttackDamage;
}

int				ScavTrap::getArmorDamageReduction(void) const {
	return this->_armorDamageReduction;
}

int				ScavTrap::getFartAttackDamage(void) const {
	return this->_fartAttackDamage;
}

int				ScavTrap::getDanceAttackDamage(void) const {
	return this->_danceAttackDamage;
}

int				ScavTrap::getPeanutButterAttackDamage(void) const {
	return this->_peanutButterAttackDamage;
}

int				ScavTrap::getBubblesAttackDamage(void) const {
	return this->_bubblesAttackDamage;
}

int				ScavTrap::getTicklesAttackDamage(void) const {
	return this->_ticklesAttackDamage;
}

/* Other */
void	ScavTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints - (int)amount + this->_armorDamageReduction < 0) {
		std::cout << "SCRAV " << this->_name << " recieved " << this->_hitPoints;
		std::cout << " of damaged. It's current HP is 0. Basically dead!" << std::endl;
		this->_hitPoints = 0;
	} else {
		this->_hitPoints = this->_hitPoints - amount + this->_armorDamageReduction;
		std::cout << "SCRAV " << this->_name << " recieved " << amount;
		std::cout << " of damaged. It's current HP is " << this->_hitPoints << std::endl;
	}

}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints + (int)amount >= this->_maxHitPoints) {
		std::cout << "SCRAV " << this->_name << " healed itself ";
		std::cout << (this->_maxHitPoints - this->_hitPoints); 
		std::cout << " points. New HP: " << this->_maxHitPoints;
		std::cout <<  " Now it is fully healed. " << std::endl;
		this->_hitPoints = this->_maxHitPoints;
	} else {
		this->_hitPoints += amount;
		std::cout << "SCRAV " << this->_name << " healed itself ";
		std::cout << amount << " points. New HP: "<< this->_hitPoints << std::endl;
	}
}


//Challenges

void	ScavTrap::challengeNewComer(void) const {
	srand(clock());
	std::cout << this->_challenges[rand() % this->_nChallenges] << std::endl;
}

//Attacks

void	ScavTrap::rangedAttack(std::string const &target) const {
	std::cout << "SCRAV " << this->_name << " ranged attacks " << target;
	std::cout << " causing " << this->_rangedAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ScavTrap::meleeAttack(std::string const &target) const {
	std::cout << "SCRAV " << this->_name << " melee attacks " << target;
	std::cout << " causing " << this->_meleeAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ScavTrap::fartAttack(std::string const &target) const {
	std::cout << "SCRAV " << this->_name << " fart attacks " << target;
	std::cout << " causing " << this->_fartAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ScavTrap::danceAttack(std::string const &target) const {
	std::cout << "SCRAV " << this->_name << " dance attacks " << target;
	std::cout << " causing " << this->_danceAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ScavTrap::peanutButterAttack(std::string const &target) const {
	std::cout << "SCRAV " << this->_name << " peanut butter attacks " << target;
	std::cout << " causing " << this->_peanutButterAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ScavTrap::bubblesAttack(std::string const &target) const {
	std::cout << "SCRAV " << this->_name << " bubbles attacks " << target;
	std::cout << " causing " << this->_bubblesAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	ScavTrap::ticklesAttack(std::string const &target) const {
	std::cout << "SCRAV " << this->_name << " tickles attacks " << target;
	std::cout << " causing " << this->_ticklesAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

std::string const	ScavTrap::_challenges[] = {
	"Put up or shut up!" , "Step up!", "Bring it on!",
	"Care to step outside?" , "Wanna piece of me?" ,
	"Let's go, pal!" , "Just me and you, later, buddy!",
	"¡¿Un tiro o qué?!"
};

int const			ScavTrap::_nChallenges = 8;
