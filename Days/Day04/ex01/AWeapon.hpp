/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:17:04 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 19:46:18 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>
#include <string>

class AWeapon {

public:
	/* Constructors */
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const &src);

	/* Destructor */
	virtual ~AWeapon(void);

	/* Operators */
	AWeapon	&operator=(AWeapon const &rhs);

	/* Getters and setters */
	std::string virtual getName(void) const;
	int getAPCost(void) const;
	int getDamage(void) const;

	/* Other */
	virtual void attack(void) const = 0;

protected:
	AWeapon(void);
	std::string	_name;
	int			_APCost;
	int			_damage;

private:

};

#endif