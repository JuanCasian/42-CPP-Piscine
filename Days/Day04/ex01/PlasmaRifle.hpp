/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:44:52 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 18:49:11 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMA_RIFLE_HPP
#define PLASMA_RIFLE_HPP

#include <iostream>
#include <string>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:
	/* Constructors */
	PlasmaRifle(void);
	PlasmaRifle(PlasmaRifle const &src);

	/* Destructor */
	virtual ~PlasmaRifle(void);

	/* Operators */
	PlasmaRifle	&operator=(PlasmaRifle const &rhs);

	/* Getters and setters */

	/* Other */
	void attack(void) const;
	
protected:

private:

};

#endif