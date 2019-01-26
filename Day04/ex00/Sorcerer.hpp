/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:02:09 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/26 14:02:21 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include <string>
#include <ostream>
#include "Victim.hpp"

class Sorcerer {
public:
    /* Constructors */
    Sorcerer(void);
    Sorcerer(std::string name, std::string title);
    Sorcerer(Sorcerer const & src);

    /* Destructor */
    ~Sorcerer(void);

    /* Operator */
    Sorcerer &      operator=(Sorcerer const & rhs);

    void            polymorph(Victim const &victim) const;

    /* getters and setters */
    std::string    getName(void) const;
    void   setName(std::string name);
    std::string    getTitle(void) const;
    void   setTitle(std::string title);


protected:

private:
    std::string     _name;
    std::string     _title;
};

std::ostream &  operator<<(std::ostream &out, Sorcerer const &rhs);
#endif
