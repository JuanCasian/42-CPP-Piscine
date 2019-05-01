/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:09:09 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 15:09:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

Zombie::Zombie (void) {
    return ;
}

Zombie::~Zombie (void) {
    return ;
}

std::string Zombie::get_name(void) const {
    return this->_name;
}

std::string Zombie::get_type(void) const {
    return this->_type;
}

void        Zombie::set_name(std::string name) {
    this->_name = name;
}

void        Zombie::set_type(std::string type) {
    this->_type = type;
}

void        Zombie::announce(void) const {
    std::cout << "<" << this->get_name() << " (" << this->get_type() << ")> Braiiiiiiinnnssss..." << std::endl;
}
