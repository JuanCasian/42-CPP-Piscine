/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CanvasObjList.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:54:39 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/05 23:33:11 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CanvasObjList.hpp"

/* Constructors */
CanvasObjList::CanvasObjList(void) : _head(NULL) {
	return ;
}

CanvasObjList::CanvasObjList(CanvasObjList const &src) {
	*this = src;
	return ;
}

/* Destructor */
CanvasObjList::~CanvasObjList(void) {
	CanvasObj *tmp;
	CanvasObj *prev;
	
	if (!this->_head)
		return ;
	if (!this->_head->getNext()) {
		delete this->_head;
		this->_head = NULL;
	}
	tmp = this->_head->getNext();
	prev = this->_head;
	while (tmp) {
		delete prev;
		prev = tmp;
		tmp = tmp->getNext();
	}
	delete prev;
	return ;
}

/* Operator */
CanvasObjList	&CanvasObjList::operator=(CanvasObjList const &rhs) {
	this->_head = rhs.getHead();
	return *this;
}

/* Other */
void	CanvasObjList::push(CanvasObj *obj) {
	if (!this->_head) {
		this->_head = obj;
		obj->setNext(NULL);
		obj->setPrev(NULL);
		return ;
	}
	obj->setNext(this->_head);
	obj->setPrev(NULL);
	this->_head = obj;
	return ;
}

void	CanvasObjList::pop(CanvasObj *obj) {
	if (!obj)
		return ;

	if (this->_head == obj) {
		this->_head = this->_head->getNext();
	}
	if (obj->getNext() != NULL)
		obj->getNext()->setPrev(obj->getPrev());
	
	if (obj->getPrev() != NULL)
		obj->getPrev()->setNext(obj->getNext());
	
	return ;
}

/* Getters and Setters */
CanvasObj	*CanvasObjList::getHead(void) const {
	return this->_head;
}