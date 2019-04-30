/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:07:23 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/25 22:07:25 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* Constructors */
ScavTrap::ScavTrap(std::string name) {
    std::cout << name << " says: " << "Hey everybody! Check out my package! while being created." << std::endl;
    this->setHitPoints(100);
    this->setMaxHitPoints(100);
    this->setEnergyPoints(50);
    this->setMaxEnergyPoints(50);
    this->setLevel(1);
    this->setName(name);
    this->setMeleeAttackDamage(20);
    this->setRangedAttackDamage(15);
    this->setArmorDamageReduction(3);
    return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
    *this = src;
    return ;
}

/* Destructor */
ScavTrap::~ScavTrap(void) {
    std::cout << this->getName() << "said: Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
    return ;
}

/* Operator */
ScavTrap &     ScavTrap::operator=(ScavTrap const & rhs) {
    if (this != &rhs) {
        this->setHitPoints(rhs.getHitPoints());
        this->setMaxHitPoints(rhs.getMaxHitPoints());
        this->setEnergyPoints(rhs.getEnergyPoints());
        this->setMaxEnergyPoints(rhs.getMaxEnergyPoints());
        this->setLevel(rhs.getLevel());
        this->setName(rhs.getName());
        this->setMeleeAttackDamage(rhs.getMeleeAttackDamage());
        this->setRangedAttackDamage(rhs.getRangedAttackDamage());
        this->setGrenadeAttackDamage(rhs.getGrenadeAttackDamage());
        this->setFartAttackDamage(rhs.getFartAttackDamage());
        this->setFreezingAttackDamage(rhs.getFreezingAttackDamage());
        this->setArmorDamageReduction(rhs.getArmorDamageReduction());
    }
    return *this;
}

void    ScavTrap::rangedAttack(std::string const & target) {
    std::cout << "FR4G-TP " << this->getName() << " attacks " << target \
    << " at range, causing " << this->getRangedAttackDamage() << " points of damage!" << std::endl;
    std::cout << "Present for you!" << std::endl;
}

void    ScavTrap::meleeAttack(std::string const & target) {
    std::cout << "FR4G-TP " << this->getName() << " melee attacks " << target \
    << ", causing " << this->getMeleeAttackDamage() << " points of damage!" << std::endl;
    std::cout << "Take that!" << std::endl;
}

void    ScavTrap::takeDamage(unsigned int amount) {
    this->setHitPoints(this->getHitPoints() - amount + this->getArmorDamageReduction());
    if (this->getHitPoints() < 0)
        this->setHitPoints(0);
    std::cout << "FR4G-TP " << this->getName() << " tooked some damage, the new HP is " \
    << this->getHitPoints() << std::endl;
}

void    ScavTrap::beRepaired(unsigned int amount) {
    this->setHitPoints(this->getHitPoints() + amount);
    if (this->getHitPoints() > this->getMaxHitPoints())
        this->setHitPoints(this->getMaxHitPoints());
    std::cout << "FR4G-TP " << this->getName() << " was repaired, the new HP is " \
    << this->getHitPoints() << std::endl;
}

/* Getters and setters */

int    ScavTrap::getHitPoints(void) const{
    return this->_hitPoints;
}

void   ScavTrap::setHitPoints(int hitPoints) {
    this->_hitPoints = hitPoints;
}

int    ScavTrap::getMaxHitPoints(void) const{
    return this->_maxHitPoints;
}

void   ScavTrap::setMaxHitPoints(int maxHitPoints) {
    this->_maxHitPoints = maxHitPoints;
}

int   ScavTrap::getEnergyPoints(void) const{
    return this->_energyPoints;
}

void  ScavTrap::setEnergyPoints(int energyPoints) {
    this->_energyPoints = energyPoints;
}

int    ScavTrap::getMaxEnergyPoints(void) const{
    return this->_maxEnergyPoints;
}

void   ScavTrap::setMaxEnergyPoints(int maxEnergyPoints) {
    this->_maxEnergyPoints = maxEnergyPoints;
}

int    ScavTrap::getLevel(void) const{
    return this->_level;
}

void   ScavTrap::setLevel(int level) {
    this->_level = level;
}

std::string    ScavTrap::getName(void) const{
    return this->_name;
}

void   ScavTrap::setName(std::string name) {
    this->_name = name;
}

int    ScavTrap::getMeleeAttackDamage(void) const{
    return this->_meleeAttackDamage;
}

void   ScavTrap::setMeleeAttackDamage(int meleeAttackDamage) {
    this->_meleeAttackDamage = meleeAttackDamage;
}

int    ScavTrap::getRangedAttackDamage(void) const{
    return this->_rangedAttackDamage;
}

void   ScavTrap::setRangedAttackDamage(int rangedAttackDamage) {
    this->_rangedAttackDamage = rangedAttackDamage;
}

int    ScavTrap::getArmorDamageReduction(void) const{
    return this->_armorDamageReduction;
}

void   ScavTrap::setArmorDamageReduction(int armorDamageReduction) {
    this->_armorDamageReduction = armorDamageReduction;
}
