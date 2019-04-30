/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:24:55 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 14:25:11 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name){
    this->_name = name;
    std::cout << "The pony: " << this->_name << " was born!" << std::endl;
    return ;
}

Pony::~Pony(void){
    std::cout << "The pony: " << this->_name << " just died :(" << std::endl;
    return ;
}
