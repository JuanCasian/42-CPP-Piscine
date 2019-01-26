/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:56:21 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/25 19:56:33 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* Constructors */
FragTrap::FragTrap(std::string name) {
    std::cout << name << " says: " << "Hey everybody! Check out my package! while being created." << std::endl;
    this->setHitPoints(100);
    this->setMaxHitPoints(100);
    this->setEnergyPoints(100);
    this->setMaxEnergyPoints(100);
    this->setLevel(1);
    this->setName(name);
    this->setMeleeAttackDamage(30);
    this->setRangedAttackDamage(20);
    this->setArmorDamageReduction(5);
    this->setGrenadeAttackDamage(40);
    this->setFartAttackDamage(100);
    this->setFreezingAttackDamage(10);
    return ;
}

FragTrap::FragTrap(FragTrap const & src) {
    *this = src;
    return ;
}

/* Destructor */
FragTrap::~FragTrap(void) {
    std::cout << this->getName() << "said: Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
    return ;
}

/* Operator */
FragTrap &     FragTrap::operator=(FragTrap const & rhs) {
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

void    FragTrap::rangedAttack(std::string const & target) {
    std::cout << "FR4G-TP " << this->getName() << " attacks " << target \
    << " at range, causing " << this->getRangedAttackDamage() << " points of damage!" << std::endl;
    std::cout << "Present for you!" << std::endl;
}

void    FragTrap::meleeAttack(std::string const & target) {
    std::cout << "FR4G-TP " << this->getName() << " melee attacks " << target \
    << ", causing " << this->getMeleeAttackDamage() << " points of damage!" << std::endl;
    std::cout << "Take that!" << std::endl;
}

void    FragTrap::grenadeAttack(std::string const & target) {
    std::cout << "FR4G-TP " << this->getName() << " grenade attacks " << target \
    << ", causing " << this->getGrenadeAttackDamage() << " points of damage!" << std::endl;
    std::cout << "Grenaaaade!" << std::endl;
}

void    FragTrap::fartAttack(std::string const & target) {
    std::cout << "FR4G-TP " << this->getName() << " fart attacks " << target \
    << ", causing " << this->getFartAttackDamage() << " points of damage!" << std::endl;
    std::cout << "** fart noise **" << std::endl;
}

void    FragTrap::freezingAttack(std::string const & target) {
    std::cout << "FR4G-TP " << this->getName() << " freezing attacks " << target \
    << ", causing " << this->getFreezingAttackDamage() << " points of damage!" << std::endl;
    std::cout << "Aww! Now I want a snow cone." << std::endl;
}

void    FragTrap::takeDamage(unsigned int amount) {
    this->setHitPoints(this->getHitPoints() - amount + this->getArmorDamageReduction());
    if (this->getHitPoints() < 0)
        this->setHitPoints(0);
    std::cout << "FR4G-TP " << this->getName() << " tooked some damage, the new HP is " \
    << this->getHitPoints() << std::endl;
}

void    FragTrap::beRepaired(unsigned int amount) {
    this->setHitPoints(this->getHitPoints() + amount);
    if (this->getHitPoints() > this->getMaxHitPoints())
        this->setHitPoints(this->getMaxHitPoints());
    std::cout << "FR4G-TP " << this->getName() << " was repaired, the new HP is " \
    << this->getHitPoints() << std::endl;
}

void    FragTrap::vaulthunter_dot_exe(std::string const & target) {
    void (FragTrap::*functions[])(std::string const & target) = {
        &FragTrap::rangedAttack,
        &FragTrap::meleeAttack,
        &FragTrap::grenadeAttack,
        &FragTrap::fartAttack,
        &FragTrap::freezingAttack
    };
    if (this->getEnergyPoints() >= 25)
    {
        (this->*functions[rand() % 5])(target);
        this->setEnergyPoints(this->getEnergyPoints() - 25);
    }
    else
        std::cout << "There is not enough energy Points" << std::endl;
}

/* Getters and setters */

int    FragTrap::getHitPoints(void) const{
    return this->_hitPoints;
}

void   FragTrap::setHitPoints(int hitPoints) {
    this->_hitPoints = hitPoints;
}

int    FragTrap::getMaxHitPoints(void) const{
    return this->_maxHitPoints;
}

void   FragTrap::setMaxHitPoints(int maxHitPoints) {
    this->_maxHitPoints = maxHitPoints;
}

int   FragTrap::getEnergyPoints(void) const{
    return this->_energyPoints;
}

void  FragTrap::setEnergyPoints(int energyPoints) {
    this->_energyPoints = energyPoints;
}

int    FragTrap::getMaxEnergyPoints(void) const{
    return this->_maxEnergyPoints;
}

void   FragTrap::setMaxEnergyPoints(int maxEnergyPoints) {
    this->_maxEnergyPoints = maxEnergyPoints;
}

int    FragTrap::getLevel(void) const{
    return this->_level;
}

void   FragTrap::setLevel(int level) {
    this->_level = level;
}

std::string    FragTrap::getName(void) const{
    return this->_name;
}

void   FragTrap::setName(std::string name) {
    this->_name = name;
}

int    FragTrap::getMeleeAttackDamage(void) const{
    return this->_meleeAttackDamage;
}

void   FragTrap::setMeleeAttackDamage(int meleeAttackDamage) {
    this->_meleeAttackDamage = meleeAttackDamage;
}

int    FragTrap::getRangedAttackDamage(void) const{
    return this->_rangedAttackDamage;
}

void   FragTrap::setRangedAttackDamage(int rangedAttackDamage) {
    this->_rangedAttackDamage = rangedAttackDamage;
}

int    FragTrap::getGrenadeAttackDamage(void) const{
    return this->_grenadeAttackDamage;
}

void   FragTrap::setGrenadeAttackDamage(int grenadeAttackDamage) {
    this->_grenadeAttackDamage = grenadeAttackDamage;
}

int    FragTrap::getFartAttackDamage(void) const{
    return this->_fartAttackDamage;
}

void   FragTrap::setFartAttackDamage(int fartAttackDamage) {
    this->_fartAttackDamage = fartAttackDamage;
}

int    FragTrap::getFreezingAttackDamage(void) const{
    return this->_freezingAttackDamage;
}

void   FragTrap::setFreezingAttackDamage(int freezingAttackDamage) {
    this->_freezingAttackDamage = freezingAttackDamage;
}

int    FragTrap::getArmorDamageReduction(void) const{
    return this->_armorDamageReduction;
}

void   FragTrap::setArmorDamageReduction(int armorDamageReduction) {
    this->_armorDamageReduction = armorDamageReduction;
}
