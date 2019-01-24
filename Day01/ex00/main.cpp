/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:25:00 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/23 14:25:11 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void    ponyOnTheHeap(void) {
    std::cout << "Pony allocated on the heap" << std::endl;
    Pony *myHeapPony = new Pony("Stalone");
    delete myHeapPony;
}

void    ponyOnTheStack(void)
{
    std::cout << "Pony allocated on the stack" << std::endl;
    Pony myStackPony = Pony("Silvestre");
    return ;
}

int     main(void)
{
    ponyOnTheHeap();
    ponyOnTheStack();
    return (0);
}
