/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:52:43 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/03 16:09:08 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap{

public:
	/* Constructors & Destructors */
	SuperTrap(SuperTrap const &src);
	SuperTrap(std::string name);
	~SuperTrap(void);

	/* Operators overload */
	SuperTrap	&operator=(SuperTrap const &rhs);

	/* Getters and Setters */

	/* Other */

private:
	SuperTrap(void);
	
};

#endif