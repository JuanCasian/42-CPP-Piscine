/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:20:51 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 18:21:06 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <stdlib.h>

ZombieHorde::ZombieHorde(int N) {
    Zombie      *zombies = new Zombie[N];
    std::string names[] = {"Dafna", "Ahmed", "Goronwy", "Hunfrid", "Pompey",
               "Jorunnr", "Margareta", "Adena", "Jasna", "Phuntsok"};

    for (int i = 0; i < N; i++) {
        zombies[i].set_name(names[rand() % 10]);
        zombies[i].set_type("Default");
    }
    this->set_zombies(zombies);
    this->set_nb_zombies(N);
    return ;
}

ZombieHorde::~ZombieHorde(void) {
    delete [] this->_zombies;
    return ;
}

void    ZombieHorde::announce(void) const{
    Zombie  *zombies;
    int     len;

    zombies = this->get_zombies();
    len = this->get_nb_zombies();
    for (int i = 0; i < len; i++) {
        zombies[i].announce();
    }
}

Zombie* ZombieHorde::get_zombies(void) const{
    return this->_zombies;
}

int     ZombieHorde::get_nb_zombies(void) const{
    return this->_nb_zombies;
}

void    ZombieHorde::set_zombies(Zombie* zombies) {
    this->_zombies = zombies;
}

void    ZombieHorde::set_nb_zombies(int n) {
    this->_nb_zombies = n;
}
