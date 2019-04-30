/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:34:53 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/27 15:35:01 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logic.hpp"

/* Constructors */
Logic::Logic(void) {
    return ;
}

Logic::Logic(WINDOW* win, Player* player) {
	int x;
    int y;
    getmaxyx(win, y, x);
	this->_maxy = y;
	this->_maxx = x;
	this->_minx = 0;
	this->_miny = 0;
	this->_eList = new EnemyList();
	this->_bList = new BulletList();
	this->_player = player;
	this->_win = win;
    return ;
}

Logic::Logic(Logic const & src) {
    *this = src;
    return ;
}

/* Destructor */
Logic::~Logic(void) {
    return ;
}

/* Operator */
Logic &     Logic::operator=(Logic const & rhs) {
    if (this != &rhs) {
		this->_eList = rhs.getEList();
		this->_bList = rhs.getBList();
		this->_player = rhs.getPlayer();
		this->_maxy = getMaxy();
		this->_maxx = getMaxx();
		this->_minx = getMinx();
		this->_miny = getMiny();
		this->_win = getWin();

	}
    return *this;
}

void 	Logic::moveAll(void) {
	EnemyNode* tmpe;
	BulletNode* tmpb;

	tmpe = this->_eList->getHead();
	tmpb = this->_bList->getHead();

	while (tmpe) {
		tmpe->enemy->move();
		tmpe = tmpe->next;
	}

	while(tmpb) {
		tmpb->bullet->move();
		tmpb = tmpb->next;
	}
}

void 	Logic::displayAll(void) const {
	EnemyNode* tmpe;
	BulletNode* tmpb;

	tmpe = this->_eList->getHead();
	tmpb = this->_bList->getHead();

	while (tmpe) {
		tmpe->enemy->display();
		tmpe = tmpe->next;
	}

	while(tmpb) {
		tmpb->bullet->display();
		tmpb = tmpb->next;
	}
	this->_player->display();
	wrefresh(this->_win);
}

int    Logic::checkPlayerColision(void) {
	EnemyNode* 	tmpe;
	Enemy*		enemy;
	Player*		player;

	tmpe = this->_eList->getHead();
	player = this->_player;
	while (tmpe) {
		enemy = tmpe->enemy;
		if (player->getPosx() == enemy->getPosx() && player->getPosy() == enemy->getPosy()){
			player->setLifes(player->getLifes() - 1);
			this->_eList->deleteNode(tmpe);
			delete enemy;
			break;
		}
		tmpe = tmpe->next;
	}
	if (player->getLifes() <= 0)
		return (0);
	return (1);
}

void    Logic::checkBulletCollision(void) {
	EnemyNode* 	tmpe;
	BulletNode* tmpb;
	EnemyNode* 	dele;
	BulletNode* delb;
	Enemy*		enemy;
	Bullet*		bullet;
	int			flag = 0;

	tmpe = this->_eList->getHead();
	while (tmpe) {
		tmpb = this->_bList->getHead();
		flag = 0;
		while (tmpb) {
			enemy = tmpe->enemy;
			bullet = tmpb->bullet;
			if (bullet->getPosx() >= enemy->getPosx() && bullet->getPosy() == enemy->getPosy()) {
				dele = tmpe;
				tmpe = tmpe->next;
				this->_eList->deleteNode(dele);
				enemy->move();
				delete enemy;
				delb = tmpb;
				tmpb = tmpb->next;
				this->_bList->deleteNode(delb);
				bullet->move();
				delete bullet;
				flag = 1;
				break;
			}
			else
				flag = 0;
			tmpb = tmpb->next;

		}
		if (!flag)
			tmpe = tmpe->next;
	}
}

void 	Logic::checkOB(void) {
	EnemyNode* tmpe;
	BulletNode* tmpb;
	Enemy*		enemy;
	Bullet*		bullet;
	EnemyNode* 	dele;
	BulletNode* delb;

	tmpe = this->_eList->getHead();
	tmpb = this->_bList->getHead();

	while (tmpe) {
		enemy = tmpe->enemy;
		if (enemy->getPosx() <= 0) {
			dele = tmpe;
			tmpe = tmpe->next;
			this->_eList->deleteNode(dele);
			enemy->move();
			delete enemy;
		}
		else
			tmpe = tmpe->next;
	}

	while(tmpb) {
		bullet = tmpb->bullet;
		if (bullet->getPosx() >= this->_maxx) {
			delb = tmpb;
			tmpb = tmpb->next;
			this->_bList->deleteNode(delb);
			bullet->move();
			delete bullet;
		}
		else
			tmpb = tmpb->next;
	}
	this->_player->display();
	wrefresh(this->_win);
}

void 	Logic::createEnemy(void) {
	int posx;
	int posy;

	posx = this->_maxx - 2;
	posy = (rand() % (this->_maxy - 2)) + 1;
	Enemy*	enemy = new Enemy(posx, posy, this->_win);
	this->_eList->addNode(enemy);
	enemy->display();
}

int    Logic::checkInput(void) {
    int choice = wgetch(this->_win);
    switch(choice)
    {
    case KEY_UP:
      	this->_player->moveUp();
      	break;
    case KEY_DOWN:
      	this->_player->moveDown();
      	break;
    case KEY_LEFT:
       	this->_player->moveLeft();
      	break;
    case KEY_RIGHT:
      	this->_player->moveRight();
      	break;
    case 32:
      	this->shot();
      	break;
	case 27:
		nodelay(this->_win, false);
   		erase();
    	werase(this->_win);
    	mvprintw(0,0, "GAME EXITED! (DOUBLE TAP TO EXIT)");
    	refresh();
    	wrefresh(this->_win);
    	wgetch(this->_win);
    	wgetch(this->_win);
    	endwin();
		exit(0);
    default:
      break;
    }
    if (this->checkPlayerColision())
        return (1);
    return (0);

}

void    Logic::shot(void) {
	Bullet* bullet = new Bullet(this->_player->getPosx() + 1, this->_player->getPosy(), this->_win);
	this->_bList->addNode(bullet);
	bullet->display();
}

/* getters and setters */
EnemyList*    Logic::getEList(void) const{
    return this->_eList;
}

void   Logic::setEList(EnemyList* eList) {
    this->_eList = eList;
}

BulletList*    Logic::getBList(void) const{
    return this->_bList;
}

void   Logic::setBList(BulletList* bList) {
    this->_bList = bList;
}

Player*    Logic::getPlayer(void) const{
    return this->_player;
}

void   Logic::setPlayer(Player* player) {
    this->_player = player;
}

int    Logic::getMaxx(void) const{
    return this->_maxx;
}

void   Logic::setMaxx(int maxx) {
    this->_maxx = maxx;
}

int 	Logic::getMaxy(void) const{
    return this->_maxy;
}

void	Logic::setMaxy(int maxy) {
    this->_maxy = maxy;
}

int    Logic::getMinx(void) const{
    return this->_minx;
}

void   Logic::setMinx(int minx) {
    this->_minx = minx;
}
int    Logic::getMiny(void) const{
    return this->_miny;
}

void   Logic::setMiny(int miny) {
    this->_miny = miny;
}

WINDOW*    Logic::getWin(void) const{
    return this->_win;
}

void   Logic::setWin(WINDOW* win) {
    this->_win = win;
}
