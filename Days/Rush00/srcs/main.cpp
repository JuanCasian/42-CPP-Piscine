/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:32:56 by csinglet          #+#    #+#             */
/*   Updated: 2019/05/05 23:40:29 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Logic.hpp"

int			main(void)
{
	Logic *l = new Logic(60, 30, 0, 1);
	
	l->cursesSetup();
	l->mainMenu();
	l->game();
	l->endScreen();
	return (0);
}
