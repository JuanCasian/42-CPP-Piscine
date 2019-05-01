/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 19:03:54 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 19:04:09 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void) {
    return ;
}

Human::~Human(void) {
    return ;
}

Brain const     &Human::getBrain(void) {
    return (this->_brain);
}

std::string     Human::identify(void) const {
    return this->_brain.identify();
}
