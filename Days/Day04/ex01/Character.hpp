/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:14:08 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 19:40:24 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {

public:
	/* Constructors */
	Character(std::string const & name);
	Character(Character const &src);

	/* Destructor */
	virtual ~Character(void);

	/* Operators */
	Character	&operator=(Character const &rhs);

	/* Getters and setters */
	int	getAP(void) const;
	void	setAP(int ap);
	AWeapon	*getWeapon(void) const;
	void	setWeapon(AWeapon *weapon);
	std::string	getName(void) const;
	void	setName(std::string name);

	/* Other */
	void	recoverAP(void);
	void	equip(AWeapon *weapon);
	void	attack(Enemy *enemy);

protected:
	Character(void);
	int		_ap;
	AWeapon *_weapon;
	std::string _name;
	

private:

};

std::ostream	&operator<<(std::ostream &o, Character const &rhs);

#endif