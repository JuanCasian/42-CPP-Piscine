/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:16:43 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 16:28:01 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include <string>
#include "Victim.hpp"

class Sorcerer {

public:
	/* Constructors & Destructors */
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const &src);
	~Sorcerer(void);

	/* Operators overload */
	Sorcerer	&operator=(Sorcerer const &rhs);

	/* Getters and Setters */
	std::string	getName(void) const;
	void	setName(std::string name);
	std::string	getTitle(void) const;
	void	setTitle(std::string title);

	/* Other */
	void	polymorph(Victim const &victim) const;

protected:
	Sorcerer(void);
	std::string	_name;
	std::string _title;

private:

};

std::ostream		&operator<<(std::ostream &o, Sorcerer const &rhs);

#endif