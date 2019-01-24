/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:25:08 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 14:25:11 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include    <iostream>
# include   <string>

class Pony {
public:
    Pony(std::string name);
    ~Pony(void);
private:
    std::string _name;
};

#endif
