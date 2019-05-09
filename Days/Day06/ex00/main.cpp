/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:14:31 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/08 21:16:02 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		Converter *con = new Converter(av[1]);
		con->printConversions();
		delete con;
	} else {
		std::cout << std::endl;
	}
	return (0);
}