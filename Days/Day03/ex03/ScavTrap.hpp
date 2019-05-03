/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:30:00 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/03 13:58:50 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
	/* Constructors & Destructors */
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);

	/* Operators overload */
	ScavTrap		&operator=(ScavTrap const &rhs);


	//Challenge
	void	challengeNewComer(void) const;

private:
	ScavTrap(void);
	
	static std::string const	_challenges[];
	static int const			_nChallenges;
};

#endif