/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:21:31 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 19:25:54 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:
	/* Constructors */
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);

	/* Destructor */
	virtual ~ShrubberyCreationForm(void);

	/* Operators */
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

	/* Other */
	virtual void	execute(Bureaucrat const & executor) const;
	
protected:
	ShrubberyCreationForm(void);

private:
	static std::string	_trees;
};

#endif