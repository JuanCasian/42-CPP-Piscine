/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:58:11 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 16:32:21 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Megaphone.class.hpp"

int		main(int ac, char **av)
{
	Megaphone mega(ac, av);

	mega.makeNoise();
	return (0);
}
