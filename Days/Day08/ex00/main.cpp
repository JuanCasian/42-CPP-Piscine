/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:06:03 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/10 16:40:10 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {
	std::vector<int>	myVector;
	std::vector<int>::iterator res;

	for (int i = 0; i < 10; i++) {
		myVector.push_back(33 + i);
	}
	res = easyfind< std::vector<int> >(myVector, 0);
	if (res == myVector.end())
		std::cout << "Number not found" << std::endl;
	else
		std::cout << "Found the number: " << *res << std::endl;
	res = easyfind< std::vector<int> >(myVector, 33);
	if (res == myVector.end())
		std::cout << "Number not found" << std::endl;
	else
		std::cout << "Found the number: " << *res << std::endl;
	
	return (0);
}