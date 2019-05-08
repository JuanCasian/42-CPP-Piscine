/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:57:51 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 15:16:48 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat *juan;
	try {
		juan = new Bureaucrat("Juan", 160);
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		juan = new Bureaucrat("Juan", 50);
		std::cout << *juan << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		juan->incrementGrade(49);
		std::cout << *juan << std::endl;
		juan->decrementGrade(149);
		std::cout << *juan << std::endl;
		juan->incrementGrade(150);
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}