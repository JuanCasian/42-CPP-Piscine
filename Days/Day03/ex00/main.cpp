/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:05:39 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/02 20:12:07 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
	FragTrap *juan = new FragTrap("Juan");

	for (int i = 0; i < 4; i++)
		juan->takeDamage(35);
	for (int i = 0; i < 3; i++)
		juan->beRepaired(50);
	juan->meleeAttack("Pepe");
	juan->rangedAttack("Francisco");
	for (int i = 0; i < 6; i++)
		juan->vaulthunter_dot_exe("Daniel");
	delete juan;
	return (0);
}