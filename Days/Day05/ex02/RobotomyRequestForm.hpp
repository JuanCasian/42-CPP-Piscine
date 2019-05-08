/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:14:41 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/07 19:20:49 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm {

public:
	/* Constructors */
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);

	/* Destructor */
	virtual ~RobotomyRequestForm(void);

	/* Operators */
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

	/* Other */
	virtual void	execute(Bureaucrat const & executor) const;
	
protected:
	RobotomyRequestForm(void);

private:
};

#endif