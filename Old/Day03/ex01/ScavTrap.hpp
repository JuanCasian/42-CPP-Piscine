/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:07:17 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/25 22:07:25 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include <string>
# include <iostream>
# include <stdlib.h>

class ScavTrap {
public:
    /* Constructors */
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const & src);

    /* Destructor */
    ~ScavTrap(void);

    /* Operator */
    ScavTrap &     operator=(ScavTrap const & rhs);

    void            rangedAttack(std::string const & target);
    void            meleeAttack(std::string const & target);

    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);

    /*Getters and setters */
    int             getHitPoints(void) const;
    void            setHitPoints(int hitPoints);
    int             getMaxHitPoints(void) const;
    void            setMaxHitPoints(int maxHitPoints);
    int             getEnergyPoints(void) const;
    void            setEnergyPoints(int energyPoints);
    int             getMaxEnergyPoints(void) const;
    void            setMaxEnergyPoints(int maxEnergyPoints);
    int             getLevel(void) const;
    void            setLevel(int level);
    std::string     getName(void) const;
    void            setName(std::string name);
    int             getMeleeAttackDamage(void) const;
    void            setMeleeAttackDamage(int meleeeAttackDamage);
    int             getRangedAttackDamage(void) const;
    void            setRangedAttackDamage(int rangedAttackDamage);
    int             getArmorDamageReduction(void) const;
    void            setArmorDamageReduction(int armorDamageReduction);




private:
    int         _hitPoints;
    int         _maxHitPoints;
    int         _energyPoints;
    int         _maxEnergyPoints;
    int         _level;
    std::string _name;
    int         _meleeAttackDamage;
    int         _rangedAttackDamage;
    int         _armorDamageReduction;
};

#endif
