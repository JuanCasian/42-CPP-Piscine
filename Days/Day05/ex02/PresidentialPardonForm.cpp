/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:49:05 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 19:13:54 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* Constructors */
PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("Presidential Pardon Form", 25, 5, target) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
AForm(src.getName(), src.getMinGrade(), src.getMinGradeExec(), src.getTarget()) {
	*this = src;
	return ;
}

/* Destructor */
PresidentialPardonForm::~PresidentialPardonForm(void) {
	return ;
}

/* Operator */
PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	this->setSigned(rhs.getSigned());
	this->setTarget(rhs.getTarget());
	return *this;
}

/* Other */
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	this->executable(executor.getGrade());
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}