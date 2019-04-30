/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:09:02 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 15:09:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ZombieEvent.hpp"

int     main(void) {
        ZombieEvent *event = new ZombieEvent();
        Zombie      *zombie1;
        Zombie      *zombie2;

        event->set_zombieType("Nalgones");
        zombie1 = event->newZombie("Pepe");
        zombie2 = event->newZombie("Toro");

        zombie1->announce();
        delete zombie1;
        event->randomChump();
        zombie2->announce();
        zombie2->set_name("Juan");
        zombie2->set_type("Loco");
        zombie2->announce();
        delete zombie2;
        return (0);
}
