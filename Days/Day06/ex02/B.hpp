/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:52:30 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/08 22:53:28 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
#define B_HPP

#include <iostream>
#include <string>
#include "Base.hpp"

class B : public Base{

public:
	/* Constructors */
	B(void);
	B(B const &src);

	/* Destructor */
	virtual ~B(void);

	/* Operators */
	B	&operator=(B const &);

	/* Getters and setters */

	/* Other */

protected:

private:
	
};

#endif
