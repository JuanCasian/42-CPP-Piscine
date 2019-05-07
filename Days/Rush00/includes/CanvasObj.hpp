/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanvasObj.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:03:33 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 19:13:58 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACANVASOBJ_HPP
#define ACANVASOBJ_HPP

#include <iostream>
#include <string>
#include <ncurses.h>

enum movements {LEFT, RIGHT, UP, DOWN};

class CanvasObj {

public:
	/* Constructors */
	CanvasObj(int x, int y, char c);
	CanvasObj(CanvasObj const &src);

	/* Destructor */
	virtual ~CanvasObj(void);

	/* Operators */
	CanvasObj	&operator=(CanvasObj const &rhs);

	/* Getters and setters */
	int			getX(void) const;
	void		setX(int x);
	int			getY(void) const;
	void		setY(int y);
	char		getC(void) const;
	void		setC(char c);
	CanvasObj	*getNext(void) const;
	void		setNext(CanvasObj *next);
	CanvasObj	*getPrev(void) const;
	void		setPrev(CanvasObj *prev);

	/* Other */
	virtual void	display(WINDOW *win) const;
	virtual int		move(WINDOW *win, int x, int y, int minx, int  miny, int maxx, int maxy);
	virtual int		inside(int minx, int  miny, int maxx, int maxy) const;
	virtual int		collides(int x, int y) const;

protected:
	CanvasObj(void);
	int			_x;
	int			_y;
	char		_c;
	CanvasObj	*_next;
	CanvasObj	*_prev;

private:

};

#endif
