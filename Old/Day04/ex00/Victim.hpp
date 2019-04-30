/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:02:16 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/26 14:02:21 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>
#include <string>
#include <ostream>

class Victim {
public:
    /* Constructors */
    Victim(void);
    Victim(std::string name);
    Victim(Victim const & src);

    /* Destructor */
    ~Victim(void);

    /* Operator */
    Victim &     operator=(Victim const & rhs);

    virtual void    getPolymorphed(void) const;

    std::string    getName(void) const;
    void   setName(std::string name);


protected:

private:
    std::string _name;
};

std::ostream &  operator<<(std::ostream &out, Victim const &rhs);
#endif
