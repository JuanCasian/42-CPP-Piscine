/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:49:14 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/08 20:51:24 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>

class Converter {

public:
	/* Constructors */
	Converter(std::string str);
	Converter(Converter const &src);

	/* Destructor */
	virtual ~Converter(void);

	/* Operators */
	Converter	&operator=(Converter const &rhs);

	/* Getters and setters */
	std::string	getStr(void) const;
	/* Other */
	void	printConversions(void) const;

protected:
	Converter(void);

private:
	std::string _str;
};

#endif
