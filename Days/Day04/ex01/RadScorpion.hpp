/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:10:29 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 19:13:54 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAD_SCORPION_HPP
#define RAD_SCORPION_HPP

#include <iostream>
#include <string>

#include "Enemy.hpp"

class RadScorpion : public Enemy {

public:
	/* Constructors */
	RadScorpion(void);
	RadScorpion(RadScorpion const &src);

	/* Destructor */
	virtual ~RadScorpion(void);

	/* Operators */
	RadScorpion	&operator=(RadScorpion const &rhs);

	/* Getters and setters */

	/* Other */

protected:

private:

};

#endif