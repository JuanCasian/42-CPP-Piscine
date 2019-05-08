/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:57:51 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 20:38:29 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main(void) {
	AForm *a1, *a2, *a3;
	Intern *newGuy = new Intern();

	a1 = newGuy->makeForm("Unknown", "pepe");
	a1 = newGuy->makeForm("presidential request", "Daniel");
	a2 = newGuy->makeForm("robotomy request", "Daniel");
	a3 = newGuy->makeForm("shrubbery request", "Daniel");

	std::cout << *a1 << std::endl;
	std::cout << *a2 << std::endl;
	std::cout << *a3 << std::endl;
	return (0);
}