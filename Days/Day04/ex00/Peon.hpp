/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:28:12 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 16:37:26 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include <string>
#include "Victim.hpp"

class Peon : public Victim {

public:
	/* Constructors */
	Peon(std::string name);
	Peon(Peon const &src);

	/* Destructor */
	~Peon(void);

	/* Operators */
	Peon	&operator=(Peon const &rhs);

	/* Getters and setters */

	/* Other */
	virtual void	getPolymorphed(void) const;

protected:
	Peon(void);

private:

};

#endif