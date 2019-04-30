/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:56:31 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/25 19:56:33 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

int     main(void) {
    FragTrap *ft = new FragTrap("Juan");

    ft->rangedAttack("Pepe");
    ft->meleeAttack("Daniel");
    ft->takeDamage(50);
    ft->beRepaired(1240);
    ft->takeDamage(1500);
    ft->beRepaired(90);
    ft->vaulthunter_dot_exe("Esteban");
    ft->vaulthunter_dot_exe("Ernesto");
    return (0);
}
