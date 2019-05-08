/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:22:32 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 20:09:10 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* Constructors */
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("Schruberry Creation Form", 145, 137, target) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
AForm(src.getName(), src.getMinGrade(), src.getMinGradeExec(), src.getTarget()) {
	*this = src;
	return ;
}

/* Destructor */
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return ;
}

/* Operator */
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	this->setSigned(rhs.getSigned());
	this->setTarget(rhs.getTarget());
	return *this;
}

/* Other */
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	this->executable(executor.getGrade());
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream outfile(filename);
	outfile << this->_trees << std::endl;
	outfile.close();
	executor.getGrade();
}

std::string	ShrubberyCreationForm::_trees = "    oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n    ooo\\oo\\  /o/o\n        \\  \\/ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |\n  ______/____\\____";