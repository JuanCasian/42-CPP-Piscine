/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:46:23 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 21:45:48 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "CanvasObj.hpp"
#include "CanvasObjList.hpp"

class Player : public CanvasObj {

public:
    /* Constructors */
    Player(int x, int y);
    Player(Player const &src);

    /* Destructor */
    virtual ~Player(void);

    /* Operators */
    Player	&operator=(Player const &rhs);

    /* Getters and setters */
    CanvasObjList	*getPieces(void) const;
    void	setPieces(CanvasObjList *pieces);
    /* Other */
    int		move(WINDOW *win, int x, int y, int minx, int  miny, int maxx, int maxy);
    int		inside(int minx, int  miny, int maxx, int maxy) const;
    int		collides(CanvasObj const *obj) const;
    void	display(WINDOW *win) const;

protected:
    Player(void);
    int     collides(int x, int y) const;

private:
    CanvasObjList   *_pieces;
    
};

#endif
