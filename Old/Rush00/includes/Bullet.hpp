/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:46:23 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/27 13:46:49 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include <ncurses.h>

class Bullet {
public:
    /* Constructors */
    Bullet(void);
    Bullet(int posx, int posy, WINDOW *win);
    Bullet(Bullet const & src);

    /* Destructor */
    ~Bullet(void);

    /* Operator */
    Bullet &     operator=(Bullet const & rhs);

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
