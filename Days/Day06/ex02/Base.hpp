/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:49:25 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/08 22:49:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>

class Base {

public:
	/* Constructors */
	Base(void);
	Base(Base const &src);

	/* Destructor */
	virtual ~Base(void);

	/* Operators */
	Base	&operator=(Base const &);

	/* Getters and setters */

	/* Other */

protected:

private:
	
};

#endif
