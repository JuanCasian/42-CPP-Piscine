/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:58:48 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 16:36:33 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>
#include <string>

class Victim {

public:
	/* Constructors */
	Victim(Victim const &src);
	Victim(std::string name);

	/* Destructor */
	virtual ~Victim(void);

	/* Operators */
	Victim	&operator=(Victim const &rhs);

	/* Getters and setters */
	std::string	getName(void) const;
	void	setName(std::string name);

	/* Other */
	virtual void	getPolymorphed(void) const;

protected:
	Victim(void);
	std::string	_name;

private:

};

std::ostream	&operator<<(std::ostream &o, Victim const &rhs);

#endif