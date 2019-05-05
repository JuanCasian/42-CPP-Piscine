/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:49:53 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 19:05:04 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWER_FIST_HPP
#define POWER_FIST_HPP

#include <iostream>
#include <string>

#include "AWeapon.hpp"

class PowerFist : public AWeapon {

public:
	/* Constructors */
	PowerFist(void);
	PowerFist(PowerFist const &src);

	/* Destructor */
	virtual ~PowerFist(void);

	/* Operators */
	PowerFist	&operator=(PowerFist const &rhs);

	/* Getters and setters */

	/* Other */

protected:
	void attack(void) const;
private:
	

};

#endif