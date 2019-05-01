/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:09:13 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 15:09:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
public:
    Zombie(void);
    ~Zombie(void);

    std::string get_name(void) const; 
    std::string get_type(void) const;
    void        set_name(std::string name);
    void        set_type(std::string type);
    void        announce(void) const;
private:
    std::string _name;
    std::string _type;
};

# endif
