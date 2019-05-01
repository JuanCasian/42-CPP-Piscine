/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:36:07 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/01 16:26:44 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

public:
	/* Constructors & Destructors */
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(const int val);
	Fixed(const float val);
	~Fixed(void);

	/* operator overload */
	Fixed	&operator=(Fixed const &rhs);

	bool	operator>(Fixed const &rhs) const;
	bool	operator<(Fixed const &rhs) const;
	bool	operator>=(Fixed const &rhs) const;
	bool	operator<=(Fixed const &rhs) const;
	bool	operator==(Fixed const &rhs) const;
	bool	operator!=(Fixed const &rhs) const;

	Fixed	operator+(Fixed const &rhs) const;
	Fixed	operator-(Fixed const &rhs) const;
	Fixed	operator/(Fixed const &rhs) const;
	Fixed	operator*(Fixed const &rhs) const;

	Fixed	&operator--(void); //Pre
	Fixed	&operator++(void);
	Fixed	operator++(int n);//Post
	Fixed	operator--(int n);

	/* Getters */
	int		getRawBits(void) const;

	/* Setters */
	void	setRawBits(int const raw);

	/* other */
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed	&min(Fixed &val1, Fixed &val2);
	static Fixed const	&min(const Fixed &val1, const Fixed &val2);
	static Fixed	&max(Fixed &val1, Fixed &val2);
	static Fixed const	&max(const Fixed &val1, const Fixed &val2);

private:
	int					_val;
	static const int	_nFractionalBits;
};

std::ostream		&operator<<(std::ostream &o, Fixed const &rhs);

#endif