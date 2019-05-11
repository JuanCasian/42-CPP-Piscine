/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 21:27:04 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/10 21:33:06 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
	Span	mySpan = Span(10000);

	try {
		mySpan.shortestSpan();
	} catch(Span::NotEnoughEntries &e) {
		std::cout << "Off limit error correctly: " << e.what() << std::endl;
	}
	try {
		mySpan.longestSpan();
	} catch(Span::NotEnoughEntries &e) {
		std::cout << "Off limit error correctly: " << e.what() << std::endl;
	}
	for (int i = 0; i < 10000; i++) {
		mySpan.addNumber(i);
	}
	try {
		mySpan.addNumber(1);
		std::cout << "Failed test" << std::endl;
	} catch (Span::OffLimit &e) {
		std::cout << "Exception throwed correctly: " << e.what() << std::endl;
	}
	std::cout << "Longest span: " << mySpan.longestSpan() << std::endl;
	std::cout << "Shortest span: " << mySpan.shortestSpan() << std::endl;
	return (0);
}