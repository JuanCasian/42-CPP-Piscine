/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:32:18 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 21:54:18 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICAL_MARINE_HPP
#define TACTICAL_MARINE_HPP

#include <iostream>
#include <string>

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

public:
	/* Constructors */
	TacticalMarine(void);
	TacticalMarine(TacticalMarine const &src);

	/* Destructor */
	virtual ~TacticalMarine(void);

	/* Operators */
	TacticalMarine	&operator=(TacticalMarine const &);

	/* Getters and setters */

	/* Other */
	void 	battleCry(void) const;
	void 	rangedAttack(void) const;
	void 	meleeAttack(void) const;
	ISpaceMarine	*clone(void) const;
protected:

private:
	

};

#endif