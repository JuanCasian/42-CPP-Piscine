/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:46:45 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/27 13:46:49 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <ncurses.h>

class Player {
public:
    /* Constructors */
    Player(void);
    Player(char c, WINDOW *win);
    Player(Player const & src);

    /* Destructor */
    ~Player(void);

    /* Operator */
    Player &     operator=(Player const & rhs);

    void    moveUp(void);
    void    moveDown(void);
    void    moveLeft(void);
    void    moveRight(void);
    void    display(void) const;

    /* Getters and setters */
    int    getLifes(void) const;
    void   setLifes(int lifes);
    int    getPosx(void) const;
    void   setPosx(int posx);
    int    getPosy(void) const;
    void   setPosy(int posy);
    int    getScore(void) const;
    void   setScore(int score);
    int    getMaxx(void) const;
    void   setMaxx(int maxx);
    int    getMaxy(void) const;
    void   setMaxy(int maxy);
    int    getMinx(void) const;
    void   setMinx(int minx);
    int    getMiny(void) const;
    void   setMiny(int miny);
    char   getChar(void) const;
    void   setChar(char c);
    WINDOW*    getWin(void) const;
    void   setWin(WINDOW* win);



protected:

private:
    int     _lifes;
    int     _posx;
    int     _posy;
    int     _score;
    int     _maxy;
    int     _maxx;
    int     _minx;
    int     _miny;
    char    _c;
    WINDOW  *_win;
};

#endif
 
