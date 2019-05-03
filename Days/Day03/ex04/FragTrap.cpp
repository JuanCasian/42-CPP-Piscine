/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:16:49 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/03 15:58:57 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* Constructors & Destructors */
FragTrap::FragTrap(void) {
	std::cout << "Fragtrap constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(100,100, 100, 100, 1,
name, 30, 20, 16, 132, 55, 88, 1, 5, "FR4G-TP") {
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
	this->_type = rhs.getType();
	return *this;
}

//Attacks

void	FragTrap::vaulthunter_dot_exe(std::string const & target){
	if (this->_energyPoints < 25) {
		std::cout << "Vaulthunter could not call any other attack because your energy points are less than 25.";
		std::cout << " Energy points: " << this->_energyPoints << std::endl;
	} else {
		void		(ClapTrap::*attacks[])(std::string const &target) const = {
			&ClapTrap::fartAttack,
			&ClapTrap::danceAttack,
			&ClapTrap::peanutButterAttack,
			&ClapTrap::bubblesAttack,
			&ClapTrap::ticklesAttack
		};
		this->_energyPoints -= 25;
		std::cout << "Calling random attack, energy points left: " << this->_energyPoints << std::endl;
		srand(clock());
		(this->*attacks[rand() % this->_nAttacks])(target);
	}
}

int const FragTrap::_nAttacks = 5;
