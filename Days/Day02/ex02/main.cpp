/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:14:34 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/01 16:48:35 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	/* my test */
	Fixed v1(1);
	Fixed v2(1);

	std::cout << (v1 > v2) << std::endl;
	std::cout << (v1 < v2) << std::endl;
	std::cout << (v1 >= v2) << std::endl;
	std::cout << (v1 <= v2) << std::endl;
	std::cout << (v1 == v2) << std::endl;
	std::cout << (v1 != v2) << std::endl;
	std::cout << (v1 + v2) << std::endl;
	std::cout << (v1 - v2) << std::endl;
	v1 = v1 - 1;
	std::cout << (v1 * v2) << std::endl;
	std::cout << (v1 / v2) << std::endl;
	std::cout << (v2 / v1) << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v2-- << std::endl;
	std::cout << v2 << std::endl;
	std::cout << --v2 << std::endl;
	return 0;
}