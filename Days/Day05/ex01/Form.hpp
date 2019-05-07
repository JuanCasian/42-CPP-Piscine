/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:06:00 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 16:17:53 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {

public:
	/* Exceptions */
	class GradeTooHighException : public std::exception {
	
	public:
		/* Constructors */
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const &);
		/* Destructor */
		virtual ~GradeTooHighException(void) throw();
		/* Operators */
		GradeTooHighException	&operator=(GradeTooHighException const &);
		/* Override */
		virtual const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	
	public:
		/* Constructors */
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const &);
		/* Destructor */
		virtual ~GradeTooLowException(void) throw();
		/* Operators */
		GradeTooLowException	&operator=(GradeTooLowException const &);
		/* Override */
		virtual const char *what(void) const throw();
	};
    /* Constructors */
	Form(std::string name, int minGrade);
    Form(Form const &src);

    /* Destructor */
    virtual ~Form(void);

    /* Operators */
    Form	&operator=(Form const &rhs);

    /* Getters and setters */
	const std::string	getName(void) const;
	bool	getSigned(void) const;
	int	getMinGrade(void) const;

    /* Other */
	void	beSigned(Bureaucrat const &bureaucrat);

	static int inbound(int grade);
protected:
    Form(void);

private:
    const std::string   _name;
    bool                _signed;
    const int			_minGrade;
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);


#endif
