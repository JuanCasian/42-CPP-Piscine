/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:05:39 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/03 16:11:13 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void) {

	std::cout << "FragTrap tests: " << std::endl;

	FragTrap *juan = new FragTrap("Juan");

	for (int i = 0; i < 4; i++)
		juan->takeDamage(35);
	for (int i = 0; i < 3; i++)
		juan->beRepaired(50);
	juan->meleeAttack("Pepe");
	juan->rangedAttack("Francisco");
	for (int i = 0; i < 6; i++)
		juan->vaulthunter_dot_exe("Daniel");
	
	std::cout << std::endl << "Scavtrap tests: " << std::endl;

	ScavTrap *pedro = new ScavTrap("Pedro");

	for (int i = 0; i < 4; i++)
		pedro->takeDamage(35);
	for (int i = 0; i < 3; i++)
		pedro->beRepaired(50);
	pedro->meleeAttack("Pepe");
	pedro->rangedAttack("Francisco");
	pedro->fartAttack("Ernesto");
	pedro->danceAttack("Flan");
	pedro->peanutButterAttack("Daniel");
	pedro->bubblesAttack("Jose");
	pedro->ticklesAttack("Ramiro");
	for (int i = 0; i < 6; i++)
		pedro->challengeNewComer();

	std::cout << std::endl << "NinjaTrap tests: " << std::endl;

	NinjaTrap *daniel = new NinjaTrap("Daniel");
	NinjaTrap *amos = new NinjaTrap("Amos");

	for (int i = 0; i < 4; i++)
		daniel->takeDamage(35);
	for (int i = 0; i < 3; i++)
		daniel->beRepaired(50);
	daniel->meleeAttack("Pepe");
	daniel->rangedAttack("Francisco");
	daniel->fartAttack("Ernesto");
	daniel->danceAttack("Flan");
	daniel->peanutButterAttack("Daniel");
	daniel->bubblesAttack("Jose");
	daniel->ticklesAttack("Ramiro");
	daniel->ninjaShoebox(*juan);
	daniel->ninjaShoebox(*pedro);
	daniel->ninjaShoebox(*amos);

	

	std::cout << std::endl << "SuperTrap tests: " << std::endl;

	SuperTrap *rafa = new SuperTrap("Rafa");
	
	for (int i = 0; i < 4; i++)
		rafa->takeDamage(35);
	for (int i = 0; i < 3; i++)
		rafa->beRepaired(50);
	rafa->meleeAttack("Pepe");
	rafa->rangedAttack("Francisco");
	rafa->fartAttack("Ernesto");
	rafa->danceAttack("Flan");
	rafa->peanutButterAttack("Daniel");
	rafa->bubblesAttack("Jose");
	rafa->ticklesAttack("Ramiro");
	rafa->ninjaShoebox(*juan);
	rafa->ninjaShoebox(*pedro);
	rafa->ninjaShoebox(*amos);
	for (int i = 0; i < 6; i++)
		rafa->vaulthunter_dot_exe("Amos");

	delete pedro;
	delete juan;
	delete daniel;
	delete amos;
	delete rafa;

	return (0);
}