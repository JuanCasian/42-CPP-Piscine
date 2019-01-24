/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 19:04:11 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 19:04:17 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_CPP
# define HUMAN_CPP

#include "Brain.hpp"

class Human {
public:
    Human(void);
    ~Human(void);
    Brain const     &getBrain(void);
    std::string     identify(void) const;
private:
    Brain const _brain;
};

#endif
