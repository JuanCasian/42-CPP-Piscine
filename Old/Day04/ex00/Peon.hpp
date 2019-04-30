/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:02:03 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/26 14:02:21 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"
#include <string>
#include <iostream>

class Peon : public Victim {
public:
    /* Constructors */
    Peon(void);
    Peon(std::string name);
    Peon(Peon const & src);

    /* Destructor */
    ~Peon(void);

    /* Operator */
    Peon &     operator=(Peon const & rhs);

    void       getPolymorphed(void) const;

protected:

private:

};

#endif
