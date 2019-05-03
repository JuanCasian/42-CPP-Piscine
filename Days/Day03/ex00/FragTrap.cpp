/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:16:49 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/02 20:01:26 by jcasian          ###   ########.fr       */
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
	_rangedAttackDamage(20), _fartAttackDamage(50), 
	_danceAttackDamage(15), _peanutButterAttackDamage(1),
	_bubblesAttackDamage(90), _ticklesAttackDamage(99),
	_armorDamageReduction(5) {
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

int				FragTrap::getFartAttackDamage(void) const {
	return this->_fartAttackDamage;
}

int				FragTrap::getDanceAttackDamage(void) const {
	return this->_danceAttackDamage;
}

int				FragTrap::getPeanutButterAttackDamage(void) const {
	return this->_peanutButterAttackDamage;
}

int				FragTrap::getBubblesAttackDamage(void) const {
	return this->_bubblesAttackDamage;
}

int				FragTrap::getTicklesAttackDamage(void) const {
	return this->_ticklesAttackDamage;
}

/* Other */
void	FragTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints - (int)amount + this->_armorDamageReduction < 0) {
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
	if (this->_hitPoints + (int)amount >= this->_maxHitPoints) {
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

//Attacks

void	FragTrap::vaulthunter_dot_exe(std::string const & target){
	if (this->_energyPoints < 25) {
		std::cout << "Vaulthunter could not call any other attack because your energy points are less than 25.";
		std::cout << " Energy points: " << this->_energyPoints << std::endl;
	} else {
		void		(FragTrap::*attacks[])(std::string const &target) = {
			&FragTrap::fartAttack,
			&FragTrap::danceAttack,
			&FragTrap::peanutButterAttack,
			&FragTrap::bubblesAttack,
			&FragTrap::ticklesAttack
		};
		this->_energyPoints -= 25;
		std::cout << "Calling random attack, energy points left: " << this->_energyPoints << std::endl;
		srand(clock());
		(this->*attacks[rand() % this->_nAttacks])(target);
	}
}

void	FragTrap::rangedAttack(std::string const &target) {
	std::cout << "FR4g-TP " << this->_name << " ranged attacks " << target;
	std::cout << " causing " << this->_rangedAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	FragTrap::meleeAttack(std::string const &target) {
	std::cout << "FR4g-TP " << this->_name << " melee attacks " << target;
	std::cout << " causing " << this->_meleeAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	FragTrap::fartAttack(std::string const &target){
	std::cout << "FR4g-TP " << this->_name << " fart attacks " << target;
	std::cout << " causing " << this->_fartAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	FragTrap::danceAttack(std::string const &target){
	std::cout << "FR4g-TP " << this->_name << " dance attacks " << target;
	std::cout << " causing " << this->_danceAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	FragTrap::peanutButterAttack(std::string const &target){
	std::cout << "FR4g-TP " << this->_name << " peanut butter attacks " << target;
	std::cout << " causing " << this->_peanutButterAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	FragTrap::bubblesAttack(std::string const &target){
	std::cout << "FR4g-TP " << this->_name << " bubbles attacks " << target;
	std::cout << " causing " << this->_bubblesAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

void	FragTrap::ticklesAttack(std::string const &target){
	std::cout << "FR4g-TP " << this->_name << " tickles attacks " << target;
	std::cout << " causing " << this->_ticklesAttackDamage << " points of damage !"; 
	std::cout << std::endl;
	return ;
}

int const FragTrap::_nAttacks = 5;
