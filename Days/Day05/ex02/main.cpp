/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:57:51 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 19:55:39 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void) {
	Bureaucrat *highLevel = new Bureaucrat("Juan", 1);
	Bureaucrat *lowLevel = new Bureaucrat("Pepe", 150);
	PresidentialPardonForm *pForm = new PresidentialPardonForm("Daniel");
	RobotomyRequestForm *rForm = new RobotomyRequestForm("Amos");
	ShrubberyCreationForm *shForm = new ShrubberyCreationForm("Home");

	lowLevel->executeAForm(*pForm);
	lowLevel->executeAForm(*rForm);
	lowLevel->executeAForm(*shForm);
	highLevel->executeAForm(*pForm);
	highLevel->executeAForm(*rForm);
	highLevel->executeAForm(*shForm);

	std::cout << std::endl;

	highLevel->signAForm(*pForm);
	highLevel->signAForm(*rForm);
	highLevel->signAForm(*shForm);

	std::cout << std::endl;
	
	lowLevel->executeAForm(*pForm);
	lowLevel->executeAForm(*rForm);
	lowLevel->executeAForm(*shForm);
	highLevel->executeAForm(*pForm);
	highLevel->executeAForm(*rForm);
	highLevel->executeAForm(*shForm);
	return (0);
}