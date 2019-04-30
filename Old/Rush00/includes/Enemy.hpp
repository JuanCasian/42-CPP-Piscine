/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:46:32 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/27 13:46:49 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <ncurses.h>

class Enemy {
public:
    /* Constructors */
    Enemy(void);
    Enemy(int posx, int posy, WINDOW *win);
    Enemy(Enemy const & src);

    /* Destructor */
    ~Enemy(void);

    /* Operator */
    Enemy &     operator=(Enemy const & rhs);

    void   move(void);
    void   display(void) const;

    int    getPosx(void) const;
    void   setPosx(int posx);
    int    getPosy(void) const;
    void   setPosy(int posy);
    WINDOW*    getWin(void) const;
    void   setWin(WINDOW* win);

protected:

private:
    int _posx;
    int _posy;
    WINDOW* _win;
};

#endif
