/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemylist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 13:46:35 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/27 13:46:49 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYLIST_HPP
# define ENEMYLIST_HPP

# include "Enemy.hpp"

struct EnemyNode
{
    Enemy*      enemy;
    EnemyNode*  next;
};

class EnemyList {
public:
    /* Constructors */
    EnemyList(void);
    EnemyList(EnemyList const & src);

    /* Destructor */
    ~EnemyList(void);

    /* Operator */
    EnemyList &     operator=(EnemyList const & rhs);

    EnemyNode*      createNode(Enemy* enemy);
    void  		    addNode(Enemy* enemy);
    void       		deleteNode(EnemyNode* node);

    EnemyNode*    getHead(void) const;
    void   setHead(EnemyNode* head);
    EnemyNode*    getNext(void) const;
    void   setNext(EnemyNode* next);


protected:

private:
    EnemyNode*    _head;
    EnemyNode*    _next;
};

#endif
