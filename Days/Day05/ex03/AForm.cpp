/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:31:50 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 19:54:39 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* Constructors */
AForm::AForm(void) : _name("Default"), _minGrade(1), _minGradeExec(1) {
	return ;
}

AForm::AForm(std::string name, int minGrade, int minGradeExec, std::string target) : 
_name(name), _signed(false), _minGrade(AForm::inbound(minGrade)), 
_minGradeExec(AForm::inbound(minGradeExec)), _target(target) {
	return ;
}


AForm::AForm(AForm const &src) : _name(src.getName()), _minGrade(src.getMinGrade()), _minGradeExec(src.getMinGradeExec()) {
	*this = src;
	return ;
}

/* Destructor */
AForm::~AForm(void) {
	return ;
}

/* Operator */
AForm	&AForm::operator=(AForm const &rhs) {
	this->_signed = rhs.getSigned();
	this->_target = rhs.getTarget();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs) {
	o << rhs.getName() << " with minimum grade required: " << rhs.getMinGrade();
	o << " is " << (rhs.getSigned() == true ? "signed" : "NOT signed");
	return o;
}

/* Getters and Setters */
const std::string	AForm::getName(void) const {
	return this->_name;
}

bool	AForm::getSigned(void) const {
	return this->_signed;
}
void	AForm::setSigned(bool _signed) {
	this->_signed = _signed;
}

int	AForm::getMinGrade(void) const {
	return this->_minGrade;
}

int	AForm::getMinGradeExec(void) const {
	return this->_minGradeExec;
}

std::string	AForm::getTarget(void) const {
	return this->_target;
}
void	AForm::setTarget(std::string target) {
	this->_target = target;
}

/* Other */
void	AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_minGrade) {
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
}

void	AForm::executable(int grade) const {
	if (this->_minGradeExec < grade) {
		throw AForm::GradeTooLowException();
	}
	if (this->_signed == false) {
		throw AForm::FormNotSignedException();
	}
}

/* Static methods */
int		AForm::inbound(int grade) {
	if (grade < 1) {
		throw AForm::GradeTooHighException();
	} else if (grade > 150) {
		throw AForm::GradeTooLowException();
	}
	return (grade);
}


/* Exceptions */
/* Constructors */
AForm::GradeTooLowException::GradeTooLowException(void) {
	return ;
}
AForm::GradeTooLowException::GradeTooLowException(AForm::GradeTooLowException const &) {
return ;
}
/* Destructor */
AForm::GradeTooLowException::~GradeTooLowException(void) throw() {
	return ;
}
/* Operator */
AForm::GradeTooLowException	&AForm::GradeTooLowException::operator=(AForm::GradeTooLowException const &) {
	return *this;
}
/* What override function */
const char *AForm::GradeTooLowException::what(void) const throw() {
	return "Grade is too low.";
}

/* Constructors */
AForm::GradeTooHighException::GradeTooHighException(void) {
	return ;
}
AForm::GradeTooHighException::GradeTooHighException(AForm::GradeTooHighException const &) {
return ;
}
/* Destructor */
AForm::GradeTooHighException::~GradeTooHighException(void) throw() {
	return ;
}
/* Operator */
AForm::GradeTooHighException	&AForm::GradeTooHighException::operator=(AForm::GradeTooHighException const &) {
	return *this;
}
/* What override function */
const char *AForm::GradeTooHighException::what(void) const throw() {
	return "Grade is too high.";
}

/* Constructors */
AForm::FormNotSignedException::FormNotSignedException(void) {
	return ;
}
AForm::FormNotSignedException::FormNotSignedException(AForm::FormNotSignedException const &) {
return ;
}
/* Destructor */
AForm::FormNotSignedException::~FormNotSignedException(void) throw() {
	return ;
}
/* Operator */
AForm::FormNotSignedException	&AForm::FormNotSignedException::operator=(AForm::FormNotSignedException const &) {
	return *this;
}
/* What override function */
const char *AForm::FormNotSignedException::what(void) const throw() {
	return "Form is not signed.";
}