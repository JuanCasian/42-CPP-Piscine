/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:09:24 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 15:09:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

class ZombieEvent {
public:
    ZombieEvent(void);
    ~ZombieEvent(void);
    void    set_zombieType(std::string type);
    Zombie*  newZombie(std::string name) const;
    void    randomChump(void) const;
private:
    std::string _zombieType;
    std::string _name_pool[10];
};
