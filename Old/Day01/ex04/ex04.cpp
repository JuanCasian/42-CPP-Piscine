/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:55:22 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 18:55:24 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int     main(void) {
    std::string myStr;

    myStr = "HI THIS IS BRAIN";

    std::string *myStrPtr = &myStr;
    std::string &myStrRef = myStr;

    std::cout << *myStrPtr << std::endl;
    std::cout << myStrRef << std::endl;
}
