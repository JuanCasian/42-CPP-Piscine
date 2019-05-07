/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:31:50 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 16:19:30 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Constructors */
Form::Form(void) : _name("Default"), _minGrade(1) {
	return ;
}

Form::Form(std::string name, int minGrade) : 
_name(name), _signed(false), _minGrade(Form::inbound(minGrade)) {
	return ;
}


Form::Form(Form const &src) : _name(src.getName()), _minGrade(src.getMinGrade()) {
	*this = src;
	return ;
}

/* Destructor */
Form::~Form(void) {
	return ;
}

/* Operator */
Form	&Form::operator=(Form const &rhs) {
	this->_signed = rhs.getSigned();
	return *this;
}

/* Getters and Setters */
const std::string	Form::getName(void) const {
	return this->_name;
}

bool	Form::getSigned(void) const {
	return this->_signed;
}

int	Form::getMinGrade(void) const {
	return this->_minGrade;
}

void	Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_minGrade) {
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs) {
	o << rhs.getName() << " with minimum grade required: " << rhs.getMinGrade();
	o << " is " << (rhs.getSigned() == true ? "signed" : "NOT signed");
	return o;
}

/* Static methods */
int		Form::inbound(int grade) {
	if (grade < 1) {
		throw Form::GradeTooHighException();
	} else if (grade > 150) {
		throw Form::GradeTooLowException();
	}
	return (grade);
}

/* Exceptions */
/* Constructors */
Form::GradeTooLowException::GradeTooLowException(void) {
	return ;
}
Form::GradeTooLowException::GradeTooLowException(Form::GradeTooLowException const &) {
return ;
}
/* Destructor */
Form::GradeTooLowException::~GradeTooLowException(void) throw() {
	return ;
}
/* Operator */
Form::GradeTooLowException	&Form::GradeTooLowException::operator=(Form::GradeTooLowException const &) {
	return *this;
}
/* What override function */
const char *Form::GradeTooLowException::what(void) const throw() {
	return "Grade is too low.";
}

/* Constructors */
Form::GradeTooHighException::GradeTooHighException(void) {
	return ;
}
Form::GradeTooHighException::GradeTooHighException(Form::GradeTooHighException const &) {
return ;
}
/* Destructor */
Form::GradeTooHighException::~GradeTooHighException(void) throw() {
	return ;
}
/* Operator */
Form::GradeTooHighException	&Form::GradeTooHighException::operator=(Form::GradeTooHighException const &) {
	return *this;
}
/* What override function */
const char *Form::GradeTooHighException::what(void) const throw() {
	return "Grade is too high.";
}