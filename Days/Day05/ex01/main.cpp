/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:57:51 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 16:20:08 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Bureaucrat *highLevel = new Bureaucrat("Juan", 1);
	Bureaucrat *lowLevel = new Bureaucrat("Pepe", 150);
	Form	*lowLevelForm = new Form("low Level Form", 150);
	Form	*highLevelForm = new Form("high level form", 1);
	Form	*imposibleForm;

	try {
		imposibleForm = new Form("Imposible form", -4);
	} catch (Form::GradeTooHighException &e) {
		std::cout << "Could not create Form because: " << e.what() << std::endl;
	}
	std::cout << *highLevel << std::endl;
	std::cout << *lowLevel << std::endl;
	std::cout << *highLevelForm << std::endl;
	std::cout << *lowLevelForm << std::endl;
	
	try {
		lowLevel->signForm(*highLevelForm);
	} catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		highLevelForm->beSigned(*lowLevel);
	} catch (Form::GradeTooLowException &e) {
		std::cout << *lowLevel << " could not sign high level form because" << e.what() << std::endl;
	}

	std::cout << *highLevel << std::endl;
	std::cout << *lowLevel << std::endl;
	std::cout << *highLevelForm << std::endl;
	std::cout << *lowLevelForm << std::endl;

	try {
		lowLevel->signForm(*lowLevelForm);
		highLevel->signForm(*highLevelForm);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << *highLevel << std::endl;
	std::cout << *lowLevel << std::endl;
	std::cout << *highLevelForm << std::endl;
	std::cout << *lowLevelForm << std::endl;
	
	return (0);
}