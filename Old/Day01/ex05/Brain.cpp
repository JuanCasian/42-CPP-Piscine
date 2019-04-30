/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 19:03:42 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 19:04:09 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <sstream>

Brain::Brain(void) {
    return ;
}

Brain::~Brain(void) {
    return ;
}

std::string Brain::identify(void) const{
    std::stringstream   address;
    std::string         res;

    address << this;
    res = address.str();
        for (int i = 2; i <= (int)res.length(); i++) {
        res[i] = std::toupper(res[i]);
    }
    return (res);
}
