/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:09:20 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 15:09:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ZombieEvent.hpp"
#include <stdlib.h>

 ZombieEvent::ZombieEvent(void) {
     std::string names[] = {"Dafna", "Ahmed", "Goronwy", "Hunfrid", "Pompey",
                "Jorunnr", "Margareta", "Adena", "Jasna", "Phuntsok"};
     this->_zombieType = "Default";
     for (size_t i = 0; i < 10; i++) {
         this->_name_pool[i] = names[i];
     }
    return ;
 }

ZombieEvent::~ZombieEvent(void) {
    return ;
}

void    ZombieEvent::set_zombieType(std::string type) {
    this->_zombieType = type;
}

Zombie*  ZombieEvent::newZombie(std::string name) const{
    Zombie *res = new Zombie();
    res->set_type(this->_zombieType);
    res->set_name(name);
    return (res);
}

void    ZombieEvent::randomChump(void) const {
    Zombie  randin = Zombie();
    randin.set_type(this->_zombieType);
    randin.set_name(this->_name_pool[rand() % 10]);
    randin.announce();
}
