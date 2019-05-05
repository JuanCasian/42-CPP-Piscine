/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:44:42 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 21:54:32 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULT_TERMINATOR
#define ASSAULT_TERMINATOR

#include <iostream>
#include <string>

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {

public:
	/* Constructors */
	AssaultTerminator(void);
	AssaultTerminator(AssaultTerminator const &src);

	/* Destructor */
	virtual ~AssaultTerminator(void);

	/* Operators */
	AssaultTerminator	&operator=(AssaultTerminator const &);

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