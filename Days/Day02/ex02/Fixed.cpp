/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:45:07 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/01 16:47:45 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructors & Destructors */

Fixed::Fixed(void) : _val(0) {
	//std::cout << "Default constructor called" << std::endl;
	return ; 
}

Fixed::Fixed(Fixed const &src) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int val) {
	//std::cout << "Int constructor called" << std::endl;
	this->_val = (val << this->_nFractionalBits);
	return ;
}

Fixed::Fixed(const float val) {
	//std::cout << "Float constructor called" << std::endl;
	this->_val = (roundf(val * (1 << this->_nFractionalBits)));
	return ;
}

Fixed::~Fixed(void) {
	//std::cout << "Destructor called" << std::endl;
	return ;
}

/* operator overload */

Fixed	&Fixed::operator=(Fixed const &rhs) {
	//std::cout << "Assignation operator called" << std::endl;
	this->_val = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const &rhs) const {
	return (this->_val > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const {
	return (this->_val < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const {
	return (this->_val >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const {
	return (this->_val <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const {
	return (this->_val == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const {
	return (this->_val != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &rhs) const {
	if (rhs.toFloat() == 0)
	{
		std::cout << "You can not divide by cero, returning result: 0" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->_val / rhs.getRawBits()));
}

Fixed	Fixed::operator*(Fixed const &rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	&Fixed::operator--(void) {
	this->_val = this->_val - 1;
	return (*this);
}
Fixed	&Fixed::operator++(void) {
	this->_val = this->_val + 1;
	return (*this);
}
Fixed	Fixed::operator++(int) {
	Fixed old(*this);
	this->_val = this->_val + 1;
	return (old);
}
Fixed	Fixed::operator--(int) {
	Fixed old(*this);
	this->_val = this->_val - 1;
	return (old);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs) {
	o << rhs.toFloat();
	return o;
}
/* Getters and setters*/

int		Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_val;
}

void	Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
	return ;
}

/* Other */

float	Fixed::toFloat(void) const {
	return ((float)this->_val / (1 << this->_nFractionalBits));
}

int		Fixed::toInt(void) const {
	return (this->_val >> this->_nFractionalBits);
}

Fixed	&Fixed::min(Fixed &val1, Fixed &val2) {
	return (val1 < val2 ? val1 : val2);
}
Fixed const	&Fixed::min(const Fixed &val1, const Fixed &val2) {
	return (val1 < val2 ? val1 : val2);
}
Fixed	&Fixed::max(Fixed &val1, Fixed &val2) {
	return (val1 > val2 ? val1 : val2);
}
Fixed const	&Fixed::max(const Fixed &val1, const Fixed &val2) {
	return (val1 > val2 ? val1 : val2);
}

const int	Fixed::_nFractionalBits = 8;
