/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:07:43 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/03 13:21:37 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

public:
	/* Constructors & Destructors */
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const &src);
	~NinjaTrap(void);

	/* Operators overload */
	NinjaTrap		&operator=(NinjaTrap const &rhs);

	// Attacks
	void	ninjaShoebox(FragTrap const &ct) const;
	void	ninjaShoebox(NinjaTrap const &ct) const;
	void	ninjaShoebox(ScavTrap const &ct) const;
	

private:
	NinjaTrap(void);
};

#endif