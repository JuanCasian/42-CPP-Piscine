/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:20:26 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 20:28:09 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

public:
	/* Constructors */
	Intern(void);
	Intern(Intern const &);

	/* Destructor */
	virtual ~Intern(void);

	/* Operators */
	Intern	&operator=(Intern const &);

	/* Other */
	AForm	*makeForm(std::string form, std::string target);

protected:

private:
	
};

#endif
