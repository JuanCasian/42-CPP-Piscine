/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:43:35 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 19:05:54 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:
	/* Constructors */
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);

	/* Destructor */
	virtual ~PresidentialPardonForm(void);

	/* Operators */
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

	/* Other */
	virtual void	execute(Bureaucrat const & executor) const;
	
protected:
	PresidentialPardonForm(void);

private:
};

#endif
