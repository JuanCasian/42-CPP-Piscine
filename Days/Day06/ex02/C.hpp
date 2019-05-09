/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:53:56 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/08 22:54:36 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
#define C_HPP

#include <iostream>
#include <string>
#include "Base.hpp"

class C : public Base {

public:
	/* Constructors */
	C(void);
	C(C const &src);

	/* Destructor */
	virtual ~C(void);

	/* Operators */
	 C	&operator=(C const &);

	/* Getters and setters */

	/* Other */

protected:

private:
	
};

#endif
