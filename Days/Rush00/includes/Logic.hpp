/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logic.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:31:13 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 21:29:36 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <iostream>
#include <string>
#include "CanvasObj.hpp"
#include "CanvasObjList.hpp"
#include "Player.hpp"
#include "Timer.hpp"
#include "Enemy.hpp"
#include "EBullet.hpp"
#include "FBullet.hpp"
#include <ncurses.h>

#define FR 1.0f/60.0f
#define SR 1.0f/2.0f
#define MR 1.0f/20.0f

class Logic {

public:
	/* Constructors */
	Logic(int maxx, int maxy, int minx, int miny);
	Logic(Logic const &src);

	/* Destructor */
	virtual ~Logic(void);

	/* Operators */
	Logic	&operator=(Logic const &rhs);

	/* Getters and setters */
	int	getMaxx(void) const;
	void	setMaxx(int maxx);
	int	getMaxy(void) const;
	void	setMaxy(int maxy);
	int	getMinx(void) const;
	void	setMinx(int minx);
	int	getMiny(void) const;
	void	setMiny(int miny);
	Player	*getPlayer(void) const;
	void	setPlayer(Player *player);
	CanvasObjList	*getEnemyObjs(void) const;
	void	setEnemyObjs(CanvasObjList *enemyObjs);
	CanvasObjList	*getFriendlyObjs(void) const;
	void	setFriendlyObjs(CanvasObjList *friendlyObjs);
	WINDOW	*getWin(void) const;
	void	setWin(WINDOW *win);
	int	getLifes(void) const;
	void	setLifes(int lifes);
	int	getScore(void) const;
	void	setScore(int score);

	/* Program states */
	void	game(void);
	void	mainMenu(void);
	void	pauseMenu(void);
	void	endScreen(void);
	
	/* NCurses Setup */
	void	cursesSetup(void);

	/* Other */
	void	displayAll(void) const;
	bool	checkColisionVsPlayer(void);
	void	checkColisionVsFBullets(void);
	void	moveEnemies(void);
	void	moveFriends(void);
	void	moveAll(void);
	void	checkInput(void);

protected:
	Logic(void);

private:
	int		_maxx;
	int		_maxy;
	int		_minx;
	int		_miny;
	int		_lifes;
	int		_score;
	Player		*_player;
	CanvasObjList	*_enemyObjs;
	CanvasObjList	*_friendlyObjs;
	WINDOW			*_win;
	Timer			*_ftimer;
	Timer			*_stimer;
	Timer			*_mtimer;
};

#endif