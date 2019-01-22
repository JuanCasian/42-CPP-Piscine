/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:23:26 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 18:26:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Megaphone.class.hpp"

Megaphone::Megaphone (int ac, char **av) : ac(ac), av(av)
{
	return ;
}

Megaphone::~Megaphone(void)
{
	return ;
}

void	Megaphone::makeNoise(void) const
{
	int i;
	int	j;

	if (this->ac > 1)
	{
		i = 0;
		while (++i < this->ac)
		{
			j = -1;
			while (this->av[i][++j])
				std::cout << Megaphone::to_uppercase(av[i][j]);
			if (this->ac != 2 && i < this->ac - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
}

char	Megaphone::to_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
