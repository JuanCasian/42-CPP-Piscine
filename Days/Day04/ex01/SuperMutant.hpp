/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:03:03 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 19:10:08 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_MUTANT_HPP
#define SUPER_MUTANT_HPP

#include <iostream>
#include <string>

#include "Enemy.hpp"

class SuperMutant : public Enemy {

public:
	/* Constructors */
	SuperMutant(void);
	SuperMutant(SuperMutant const &src);

	/* Destructor */
	virtual ~SuperMutant(void);

	/* Operators */
	SuperMutant	&operator=(SuperMutant const &rhs);

	/* Getters and setters */

	/* Other */
	void	takeDamage(int damage);

protected:

private:
	

};

#endif