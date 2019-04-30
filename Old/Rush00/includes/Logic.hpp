/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logic.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:46:42 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/27 13:46:49 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LOGIC_HPP
# define LOGIC_HPP

# include <ncurses.h>
# include "EnemyList.hpp"
# include "BulletList.hpp"
# include "Player.hpp"
# include <stdlib.h>

class Logic {
public:
    /* Constructors */
    Logic(void);
	Logic(WINDOW* win, Player* player);
    Logic(Logic const & src);

    /* Destructor */
    ~Logic(void);

    /* Operator */
    Logic &     operator=(Logic const & rhs);

	void 	moveAll(void);
	void 	displayAll(void) const;
    int	    checkPlayerColision(void);
    void    checkBulletCollision(void);
	void 	checkOB(void);
    void    createEnemy(void);
    int    checkInput(void);
    void    shot(void);

	EnemyList*    getEList(void) const;
	void   setEList(EnemyList* eList);
	BulletList*    getBList(void) const;
	void   setBList(BulletList* bList);
	Player*    getPlayer(void) const;
	void   setPlayer(Player* player);
	int    getMaxx(void) const;
	void   setMaxx(int maxx);
	int    getMaxy(void) const;
	void   setMaxy(int maxy);
	int    getMinx(void) const;
	void   setMinx(int minx);
	int    getMiny(void) const;
	void   setMiny(int miny);
	WINDOW*    getWin(void) const;
	void   setWin(WINDOW* win);

protected:

private:
    EnemyList*  _eList;
    BulletList* _bList;
    Player*     _player;
	WINDOW*		_win;
	int			_maxx;
	int			_maxy;
	int			_minx;
	int			_miny;
};

#endif
