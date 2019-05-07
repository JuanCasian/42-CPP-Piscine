/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanvasObjList.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:48:47 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 19:16:07 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVASOBJLIST_HPP
#define CANVASOBJLIST_HPP

#include <iostream>
#include <string>
#include "CanvasObj.hpp"

class CanvasObjList {

public:
	/* Constructors */
	CanvasObjList(void);
	CanvasObjList(CanvasObjList const &src);

	/* Destructor */
	virtual ~CanvasObjList(void);

	/* Operators */
	CanvasObjList	&operator=(CanvasObjList const &rhs);

	/* Getters and setters */
	CanvasObj	*getHead(void) const;
	
	/* Other */
	void	push(CanvasObj *obj);
	void	pop(CanvasObj *obj);

protected:

private:
	CanvasObj *_head;
};

#endif
