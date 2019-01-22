/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:58:11 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 18:36:36 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	to_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int		main(int ac, char **av)
{
	int i;
	int	j;

	if (ac > 1)
	{
		i = 0;
		while (++i < ac)
		{
			j = -1;
			while (av[i][++j])
				std::cout << to_uppercase(av[i][j]);
			if (ac != 2 && i < ac - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return (0);
}
