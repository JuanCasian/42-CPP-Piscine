/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:34:56 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/27 15:35:01 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bullet.hpp"
#include "BulletList.hpp"
#include "Enemy.hpp"
#include "EnemyList.hpp"
#include "Logic.hpp"
#include "Player.hpp"
#include <time.h>

int main(void) {
    clock_t ticks;
    clock_t score;
    int createFlag = 0;
    int moveFlag = 0;

    initscr();
    noecho();
    cbreak();
    curs_set(0);

    WINDOW* win = newwin(30, 50, 1, 0);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    keypad(win, true);
    nodelay(win, true);
    Player* p = new Player('>', win);
    Logic* l = new Logic(win, p);
    while (1) {
        box(win, 0, 0);
        ticks = clock() / (CLOCKS_PER_SEC / 32);
        score = clock() / CLOCKS_PER_SEC * 10;
        mvprintw(0, 0, "Score: %i\tTime: %i\tLifes: %i", score, score / 10, p->getLifes());
        refresh();
        l->displayAll();
        if (!l->checkInput())
            break;
        if (ticks % 2 == 0 && createFlag == 0) {
            l->createEnemy();
            createFlag = 1;
        }
        if (ticks % 2 == 0 && moveFlag == 0) {
            l->moveAll();
            if (!l->checkPlayerColision())
                break;
            l->checkOB();
            l->checkBulletCollision();

            moveFlag = 1;
        }

        if (ticks % 2 == 1) {
            createFlag = 0;
            moveFlag = 0;
        }
    }
    nodelay(win, false);
    erase();
    werase(win);
    mvprintw(0,0, "GAME OVER! (DOUBLE TAP TO EXIT)");
    refresh();
    wrefresh(win);
    wgetch(win);
    wgetch(win);
    endwin();
}
