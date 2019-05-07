/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:45:41 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 21:13:53 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <string>
#include "CanvasObj.hpp"

class Enemy : public CanvasObj {

public:
    /* Constructors */
    Enemy(int x, int y);
    Enemy(Enemy const &src);

    /* Destructor */
    virtual ~Enemy(void);

    /* Operators */
    Enemy	&operator=(Enemy const &rhs);

    /* Getters and setters */

    /* Other */
    int		move(WINDOW *win, int x, int y, int minx, int  miny, int maxx, int maxy);

protected:
    Enemy(void);

private:
    
};

#endif
