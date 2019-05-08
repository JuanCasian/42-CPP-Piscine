/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:26:38 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 20:33:13 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* Constructors */
Intern::Intern(void) {
	return ;
}

Intern::Intern(Intern const &) {
	return ;
}

/* Destructor */
Intern::~Intern(void) {
	return ;
}

/* Operator */
Intern	&Intern::operator=(Intern const &) {
	return *this;
}

AForm	*Intern::makeForm(std::string form, std::string target) {
	if (!form.compare("presidential request"))
		return (new PresidentialPardonForm(target));
	if (!form.compare("robotomy request"))
		return (new RobotomyRequestForm(target));
	if (!form.compare("shrubbery request"))
		return (new ShrubberyCreationForm(target));
	std::cout << "Error: The type of form you requested is not part of our forms." << std::endl;
	return (NULL);
}
