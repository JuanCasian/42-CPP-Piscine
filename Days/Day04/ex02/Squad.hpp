/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:14:38 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/04 22:11:31 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include <iostream>
#include <string>

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

typedef struct s_node {
	ISpaceMarine *m;
	struct s_node *next;
}				t_node;

class Squad : public ISquad {
public:
	/* Constructors */
	Squad(void);
	Squad(Squad const &src);

	/* Destructor */
	virtual ~Squad(void);

	/* Operators */
	Squad	&operator=(Squad const &rhs);

	/* Getters and setters */
	int		getCount(void) const;
	ISpaceMarine	*getUnit(int n) const;

	/* Other */
	int		push(ISpaceMarine *marine);

protected:
	static t_node	*new_node(ISpaceMarine *val);

	int				_count;
	t_node			*_head;

private:

};

#endif