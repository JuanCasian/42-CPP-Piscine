/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EBullet.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:58:42 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 21:13:03 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EBULLET_HPP
#define EBULLET_HPP

#include <iostream>
#include <string>
#include "CanvasObj.hpp"

class EBullet : public CanvasObj {

public:
    /* Constructors */
    EBullet(int x, int y);
    EBullet(EBullet const &src);

    /* Destructor */
    virtual ~EBullet(void);

    /* Operators */
    EBullet	&operator=(EBullet const &rhs);

    /* Getters and setters */

    /* Other */
	int		move(WINDOW *win, int x, int y, int minx, int  miny, int maxx, int maxy);
	int		collides(int x, int y) const;
    
protected:
    EBullet(void);

private:
    
};

#endif
