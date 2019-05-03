/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:07:43 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/02 19:59:08 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

class FragTrap {

public:
	/* Constructors & Destructors */
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	/* Operators overload */
	FragTrap		&operator=(FragTrap const &rhs);

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

	/* Other */

	
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	// Attacks
	void	vaulthunter_dot_exe(std::string const & target);
	void	rangedAttack(std::string const &target);
	void	meleeAttack(std::string const &target);
	void	fartAttack(std::string const &target);
	void	danceAttack(std::string const &target);
	void	peanutButterAttack(std::string const &target);
	void	bubblesAttack(std::string const &target);
	void	ticklesAttack(std::string const &target);
	

private:
	FragTrap(void);

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
	
	static int const 		_nAttacks;

};

#endif