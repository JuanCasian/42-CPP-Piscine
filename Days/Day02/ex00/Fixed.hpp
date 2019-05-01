/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:36:07 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/01 13:09:38 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

public:
	/* Constructors & Destructors */
	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);

	/* operator overload */
	Fixed	&operator=(Fixed const &rhs);

	/* Getters */
	int		getRawBits(void) const;

	/* Setters */
	void	setRawBits(int const raw);

private:
	int					_fixedPoint;
	static const int	_nFractionalBits;
};

#endif