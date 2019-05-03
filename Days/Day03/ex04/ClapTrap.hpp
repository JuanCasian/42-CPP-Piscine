/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:54:57 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/03 13:54:47 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class ClapTrap {

public:
	/* Constructors & Destructors */
	ClapTrap(int hitPoints, int maxHitPoints,
	int energyPoints, int maxEnergyPoints,
	int level, std::string name, int meleeAttackDamage,
	int rangedAttackDamage, int fartAttackDamage,
	int danceAttackDamage, int peanutButterAttackDamage,
	int bubblesAttackDamage, int ticklesAttackDamage,
	int armorDamageReduction, std::string type);
	
	ClapTrap(ClapTrap const &src);
	virtual ~ClapTrap(void);

	/* Operators overload */
	ClapTrap	&operator=(ClapTrap const &rhs);

	/* Getters and Setters */
	int				getHitPoints(void) const;
	int				getMaxHitPoints(void) const;
	int				getEnergyPoints(void) const;
	int				getMaxEnergyPoints(void) const;
	int				getLevel(void) const;
	std::string		getName(void) const;
	int				getMeleeAttackDamage(void) const;
	int				getRangedAttackDamage(void) const;
	int				getFartAttackDamage(void) const;
	int				getDanceAttackDamage(void) const;
	int				getPeanutButterAttackDamage(void) const;
	int				getBubblesAttackDamage(void) const;
	int				getTicklesAttackDamage(void) const;
	int				getArmorDamageReduction(void) const;
	std::string		getType(void) const;

	/* Other */

	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	// Attacks
	void	rangedAttack(std::string const &target) const;
	void	meleeAttack(std::string const &target) const;
	void	fartAttack(std::string const &target) const;
	void	danceAttack(std::string const &target) const;
	void	peanutButterAttack(std::string const &target) const;
	void	bubblesAttack(std::string const &target) const;
	void	ticklesAttack(std::string const &target) const;

protected:
	ClapTrap(void);

	int				_hitPoints;
	int				_maxHitPoints;
	int				_energyPoints;
	int				_maxEnergyPoints;
	int				_level;
	std::string		_name;
	int				_meleeAttackDamage;
	int				_rangedAttackDamage;
	int				_fartAttackDamage;
	int				_danceAttackDamage;
	int				_peanutButterAttackDamage;
	int				_bubblesAttackDamage;
	int				_ticklesAttackDamage;
	int				_armorDamageReduction;
	std::string		_type;
};

#endif