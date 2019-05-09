/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:14:25 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/08 21:17:23 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

/* Constructors */
Converter::Converter(void) {
	return ;
}

Converter::Converter(std::string str) : _str(str) {
	return ;
}

Converter::Converter(Converter const &src) {
	*this = src;
	return ;
}

/* Destructor */
Converter::~Converter(void) {
	return ;
}

/* Operator */
Converter	&Converter::operator=(Converter const &rhs) {
	this->_str = rhs.getStr();
	return *this;
}

/* Getters and Setters */
std::string	Converter::getStr(void) const {
	return this->_str;
}

/* other */
void	Converter::printConversions(void) const {
	int intVal = -1;
	float floatVal;
	double doubleVal;
	bool	intPosible = true;

	try {
		intVal = std::stoi(this->_str);
		if (intVal >= 32 && intVal <= 126) {
			std::cout << "char: " << (static_cast<char>(intVal)) << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	} catch (std::exception &) {
		std::cout << "char: impossible" << std::endl;
		intPosible = false;
	}
	if (intPosible) {
		std::cout << "int: " << intVal << std::endl;
	} else {
		std::cout << "int: imposible" << std::endl;
	}
	try {
		floatVal = std::stof(this->_str);
		if (intPosible) {
			if (intVal == floatVal) {
				std::cout << "float: " << floatVal << ".0f" << std::endl;
			} else {
				std::cout << "float: " << floatVal << "f" << std::endl;
			}
		} else {
			std::cout << "float: " << floatVal << "f" << std::endl;
		}
	} catch (std::exception &) {
		std::cout << "float: impossible" << std::endl;
	}
	try {
		doubleVal = std::stod(this->_str);
		if (intPosible) {
			if (doubleVal == intVal) {
				std::cout << "double: " << doubleVal << ".0" << std::endl;
			} else {
				std::cout << "double: " << doubleVal << std::endl;
			}
		} else {
			std::cout << "double: " << doubleVal << std::endl;
		}
	} catch (std::exception &) {
		std::cout << "double: impossible" << std::endl;
	}
}