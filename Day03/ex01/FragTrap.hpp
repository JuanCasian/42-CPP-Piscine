/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:56:25 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/25 19:56:33 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <stdlib.h>

class FragTrap {
public:
    /* Constructors */
    FragTrap(std::string name);
    FragTrap(FragTrap const & src);

    /* Destructor */
    ~FragTrap(void);

    /* Operator */
    FragTrap &     operator=(FragTrap const & rhs);

    void            rangedAttack(std::string const & target);
    void            meleeAttack(std::string const & target);
    void            grenadeAttack(std::string const & target);
    void            fartAttack(std::string const & target);
    void            freezingAttack(std::string const & target);

    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);

    void            vaulthunter_dot_exe(std::string const & target);

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
    int             getGrenadeAttackDamage(void) const;
    void            setGrenadeAttackDamage(int grenadeattackDamage);
    int             getFartAttackDamage(void) const;
    void            setFartAttackDamage(int fartAttackDamage);
    int             getFreezingAttackDamage(void) const;
    void            setFreezingAttackDamage(int freezingAttackDamage);
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
    int         _grenadeAttackDamage;
    int         _fartAttackDamage;
    int         _freezingAttackDamage;
    int         _armorDamageReduction;
};

#endif
