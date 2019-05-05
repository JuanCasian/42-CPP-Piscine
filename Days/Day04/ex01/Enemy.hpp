/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:52:56 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 19:00:14 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy {

public:
	/* Constructors */
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const &src);

	/* Destructor */
	virtual ~Enemy(void);

	/* Operators */
	Enemy	&operator=(Enemy const &rhs);

	/* Getters and setters */
	std::string		virtual getType(void) const;
	void			setType(std::string type);
	int				getHP(void) const;
	void			setHP(int hp);
	/* Other */
	virtual void	takeDamage(int damage);
	
protected:
	Enemy(void);
	int			_hp;
	std::string	_type;

private:

};

#endif