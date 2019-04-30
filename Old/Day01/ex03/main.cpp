/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:20:57 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 18:21:06 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ZombieHorde.hpp"

int     main(void) {
    ZombieHorde *zombiehorde = new ZombieHorde(7);
    zombiehorde->announce();
    delete zombiehorde;
    return (0);
}
