/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:21:04 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 18:21:06 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define    ZOMBIEHORDE_HPP
# include "Zombie.hpp"

class ZombieHorde {
public:
    ZombieHorde(int N);
    ~ZombieHorde(void);
    void    announce(void) const;
    Zombie* get_zombies(void) const;
    int     get_nb_zombies(void) const;
    void    set_zombies(Zombie* zombies);
    void    set_nb_zombies(int n);
private:
    Zombie  *_zombies;
    int     _nb_zombies;
};

# endif
