/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 16:46:43 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 23:41:13 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logic.hpp"

/* Constructors */
Logic::Logic(void) {
	return ;
}

Logic::Logic(int maxx, int maxy, int minx, int miny) : 
_maxx(maxx), _maxy(maxy), _minx(minx), _miny(miny), _lifes(1), _score(0) {
	this->_enemyObjs = new CanvasObjList();
	this->_friendlyObjs = new CanvasObjList();
	this->_player = new Player(minx + 3, maxy / 2);
	this->_ftimer = new Timer();
	this->_stimer = new Timer();
	this->_mtimer = new Timer();
}

Logic::Logic(Logic const &src) {
	*this = src;
	return ;
}

/* Destructor */
Logic::~Logic(void) {
	return ;
}

/* Operator */
Logic	&Logic::operator=(Logic const &rhs) {
	this->_maxx = rhs.getMaxx();
	this->_maxy = rhs.getMaxy();
	this->_minx = rhs.getMinx();
	this->_miny = rhs.getMiny();
	this->_player = rhs.getPlayer();
	this->_enemyObjs = rhs.getEnemyObjs();
	this->_friendlyObjs = rhs.getFriendlyObjs();
	this->_win = rhs.getWin();
	this->_lifes = rhs.getLifes();
	this->_score = rhs.getScore();
	return *this;
}

/* Program states */

void Logic::game(void)
{
	CanvasObj	*tmp;

	srand(time(NULL));
	this->_stimer->resetStartTime();
	this->_ftimer->resetStartTime();
	this->_mtimer->resetStartTime();
	werase(this->_win);
	refresh();
	wrefresh(this->_win);
	while (1) // Game loop
	{
		this->_stimer->tick();
		this->_ftimer->tick();
		this->_mtimer->tick();
		box(this->_win, 0, 0);
		if (this->_ftimer->getDeltaTime() / CLOCKS_PER_SEC >= FR) {
			this->displayAll();
			this->_ftimer->resetStartTime();
			mvprintw(0, 0, "Score: %i\tLifes: %i", this->_score, this->_lifes);
			refresh();
			wrefresh(this->_win);
		}
		if (this->_mtimer->getDeltaTime() / CLOCKS_PER_SEC >= MR) {
			this->moveAll();
			this->_mtimer->resetStartTime();
		}
		if (this->_stimer->getDeltaTime() / CLOCKS_PER_SEC >= SR) {
			this->_enemyObjs->push(new Enemy(this->_maxx - 1, (rand() % (this->_maxy - 1) + this->_miny + 1)));
			tmp = this->_enemyObjs->getHead();
			while (tmp) {
				if (tmp->getX() > this->_minx + 1 && rand() % 50 == 0) {
					this->_enemyObjs->push(new EBullet(tmp->getX() - 1, tmp->getY()));
				}
				tmp = tmp->getNext();
			}
			this->_stimer->resetStartTime();
		}
		this->checkInput();
		if (this->_lifes <= 0)
			break ;
	}
}

void Logic::mainMenu(void)
{
	werase(this->_win);
	box(this->_win, 0, 0);
	refresh();
	wrefresh(this->_win);
	mvwprintw(this->_win, this->_maxy / 2 + 1, (this->_maxx / 2) - 8, "*~~~~~~~~~~~~~~~*");
	mvwprintw(this->_win, this->_maxy / 2, (this->_maxx / 2) - 8, "* Press any key *");
	mvwprintw(this->_win, this->_maxy / 2 - 1, (this->_maxx / 2) - 8, "*~~~~~~~~~~~~~~~*");
	nodelay(this->_win, false);
	wgetch(this->_win);
	nodelay(this->_win, true);
}

void Logic::pauseMenu(void)
{
	std::string options[2] = {"* CONTINUE *", "* EXIT *"};
	bool loop = true;
	int choice = 0, input, x = this->_maxx / 2, y = this->_maxy / 2;

	werase(this->_win);
	box(this->_win, 0, 0);
	refresh();
	wrefresh(this->_win);

	while (loop == true)
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == choice)
				wattron(this->_win, A_REVERSE);
			mvwprintw(this->_win, y + i - 2, x - options[i].length(), options[i].c_str());
			wattroff(this->_win, A_REVERSE);
		}
		input = wgetch(this->_win);
		if (input == 'w' || input == KEY_UP)
			choice += (choice > 0) ? -1 : 0;
		else if (input == 's' || input == KEY_DOWN)
			choice += (choice < 2) ? 1 : 0;
		else if (input == ' ')
		{
			if (choice == 1)
			{
				nodelay(this->_win, false);
				erase();
				werase(this->_win);
				refresh();
				wrefresh(this->_win);
				endwin();
				exit(0);
			}
			loop = false;
		}
		else if (input == '\t')
			loop = false;
	}
}

void Logic::endScreen(void)
{
	int choice = -1;

	werase(this->_win);
	box(this->_win, 0, 0);
	refresh();
	wrefresh(this->_win);

	mvwprintw(this->_win, this->_maxy / 2, this->_maxx / 2 - 9, "*** GAME OVER ***");
	mvwprintw(this->_win, this->_maxy / 2 + 1, this->_maxx / 2 - 16, "*** PRESS ANYTHING TO EXIT ***");

	while (choice == -1)
		choice = wgetch(this->_win);
}

/* NCurses Setup */

void Logic::cursesSetup(void)
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	this->_win = newwin(this->_maxy, this->_maxx, this->_miny, this->_minx);
	keypad(this->_win, true);
	nodelay(this->_win, true);
	box(this->_win, 0, 0);
    refresh();
    wrefresh(this->_win);
}

/* Other */
void	Logic::displayAll(void) const {
	CanvasObj	*tmp;

	tmp = this->_enemyObjs->getHead();
	while (tmp) {
		tmp->display(this->_win);
		tmp = tmp->getNext();
	}
	tmp = this->_friendlyObjs->getHead();
	while (tmp) {
		tmp->display(this->_win);
		tmp = tmp->getNext();
	}
	this->_player->display(this->_win);
}

bool	Logic::checkColisionVsPlayer(void) {
	CanvasObj	*tmp;
	CanvasObj	*next;
	bool		flag;

	flag = false;
	tmp = this->_enemyObjs->getHead();
	while (tmp) {
		if (this->_player->collides(tmp)) {
			next = tmp->getNext();
			this->_enemyObjs->pop(tmp);
			tmp = next;
			flag = true;
		} else {
			tmp = tmp->getNext();
		}
	}
	return flag;
}

void	Logic::checkColisionVsFBullets(void) {
	CanvasObj	*tmpE;
	CanvasObj	*nextE;
	CanvasObj	*tmpF;
	CanvasObj	*nextF;
	bool		flag;

	tmpF = this->_friendlyObjs->getHead();
	while (tmpF) {
		tmpE = this->_enemyObjs->getHead();
		flag = true;
		while (tmpE && flag) {
			if (tmpE->collides(tmpF->getX(), tmpF->getY()) ||
			tmpF->collides(tmpE->getX(), tmpE->getY())) {
				nextE = tmpE->getNext();
				nextF = tmpF->getNext();
				this->_enemyObjs->pop(tmpE);
				this->_friendlyObjs->pop(tmpF);
				tmpE = nextE;
				tmpF = nextF;
				flag = false;
				this->_score += 1;
			} else {
				tmpE = tmpE->getNext();
			}
		}
		if (flag)
			tmpF = tmpF->getNext();
	}
}

void	Logic::moveEnemies(void) {
	CanvasObj *tmp;
	CanvasObj *next;

	tmp = this->_enemyObjs->getHead();
	while (tmp) {
		if (!tmp->move(this->_win, 0, 0, this->_minx, this->_miny, this->_maxx, this->_maxy)) {
			next = tmp->getNext();
			this->_enemyObjs->pop(tmp);
			tmp = next;
		} else {
			tmp = tmp->getNext();
		}
	}
	if (this->checkColisionVsPlayer()) {
		this->_lifes -= 1;
	}
	this->checkColisionVsFBullets();
}

void	Logic::moveFriends(void) {
	CanvasObj *tmp;
	CanvasObj *next;

	tmp = this->_friendlyObjs->getHead();
	while (tmp) {
		if (!tmp->move(this->_win, 0, 0, this->_minx, this->_miny, this->_maxx, this->_maxy)) {
			next = tmp->getNext();
			this->_friendlyObjs->pop(tmp);
			tmp = next;
		} else {
			tmp = tmp->getNext();
		}
	}
	this->checkColisionVsFBullets();
}

void	Logic::moveAll(void) {
	this->moveEnemies();
	this->moveFriends();
	wrefresh(this->_win);
}

void	Logic::checkInput(void) {
	int input;
	
	input = wgetch(this->_win);
	if (input == 'w' || input == KEY_UP)
		this->_player->move(this->_win, 0, -1, this->_minx, this->_miny, this->_maxx, this->_maxy);
	else if (input == 's' || input == KEY_DOWN)
		this->_player->move(this->_win, 0, 1, this->_minx, this->_miny, this->_maxx, this->_maxy);
	else if (input == 'a' || input == KEY_LEFT)
		this->_player->move(this->_win, -1, 0, this->_minx, this->_miny, this->_maxx, this->_maxy);
	else if (input == 'd' || input == KEY_RIGHT)
		this->_player->move(this->_win, 1, 0, this->_minx, this->_miny, this->_maxx, this->_maxy);
	else if (input == ' ' && this->_player->getX() < this->_maxx - 1)
		this->_friendlyObjs->push(new FBullet(this->_player->getX() + 1, this->_player->getY()));
	else if (input == '\t')
		this->pauseMenu();
	if (checkColisionVsPlayer()) {
		this->_lifes -= 1;
	}
}

/* Getters and Setters */

int	Logic::getMaxx(void) const {
	return this->_maxx;
}
void	Logic::setMaxx(int maxx) {
	this->_maxx = maxx;
}

int	Logic::getMaxy(void) const {
	return this->_maxy;
}
void	Logic::setMaxy(int maxy) {
	this->_maxy = maxy;
}

int	Logic::getMinx(void) const {
	return this->_minx;
}
void	Logic::setMinx(int minx) {
	this->_minx = minx;
}

int	Logic::getMiny(void) const {
	return this->_miny;
}
void	Logic::setMiny(int miny) {
	this->_miny = miny;
}

Player	*Logic::getPlayer(void) const {
	return this->_player;
}
void	Logic::setPlayer(Player *player) {
	this->_player = player;
}

CanvasObjList	*Logic::getEnemyObjs(void) const {
	return this->_enemyObjs;
}
void	Logic::setEnemyObjs(CanvasObjList *enemyObjs) {
	this->_enemyObjs = enemyObjs;
}

CanvasObjList	*Logic::getFriendlyObjs(void) const {
	return this->_friendlyObjs;
}
void	Logic::setFriendlyObjs(CanvasObjList *friendlyObjs) {
	this->_friendlyObjs = friendlyObjs;
}

WINDOW	*Logic::getWin(void) const {
	return this->_win;
}
void	Logic::setWin(WINDOW *win) {
	this->_win = win;
}

int	Logic::getLifes(void) const {
	return this->_lifes;
}
void	Logic::setLifes(int lifes) {
	this->_lifes = lifes;
}

int	Logic::getScore(void) const {
	return this->_score;
}
void	Logic::setScore(int score) {
	this->_score = score;
}