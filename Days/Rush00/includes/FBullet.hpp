/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FBullet.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:58:42 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 21:13:10 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FBULLET_HPP
#define FBULLET_HPP

#include <iostream>
#include <string>
#include "CanvasObj.hpp"

class FBullet : public CanvasObj {

public:
    /* Constructors */
    FBullet(int x, int y);
    FBullet(FBullet const &src);

    /* Destructor */
    virtual ~FBullet(void);

    /* Operators */
    FBullet	&operator=(FBullet const &rhs);

    /* Getters and setters */

    /* Other */
	int		move(WINDOW *win, int x, int y, int minx, int  miny, int maxx, int maxy);
	int		collides(int x, int y) const;
    
protected:
    FBullet(void);

private:
    
};

#endif
