/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bulletlist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:46:35 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/27 13:46:49 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETLIST_HPP
# define BULLETLIST_HPP

# include "Bullet.hpp"

struct BulletNode
{
    Bullet*      bullet;
    BulletNode*  next;
};

class BulletList {
public:
    /* Constructors */
    BulletList(void);
    BulletList(BulletList const & src);

    /* Destructor */
    ~BulletList(void);

    /* Operator */
    BulletList &     operator=(BulletList const & rhs);

    BulletNode*      createNode(Bullet* bullet);
    void  		    addNode(Bullet* bullet);
    void       		deleteNode(BulletNode* node);

    BulletNode*    getHead(void) const;
    void   setHead(BulletNode* head);
    BulletNode*    getNext(void) const;
    void   setNext(BulletNode* next);


protected:

private:
    BulletNode*    _head;
    BulletNode*    _next;
};

#endif
