/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:02:34 by csinglet          #+#    #+#             */
/*   Updated: 2019/05/05 19:02:36 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Timer.hpp"

Timer::Timer(void)
{
	resetStartTime();
}

Timer::Timer(Timer const & src)
{
	*this = src;
}

Timer::~Timer(void)
{
	return ;
}

Timer & Timer::operator=(Timer const & rhs)
{
	if (this != &rhs)
	{

	}
	return (*this);
}

void Timer::resetStartTime(void)
{
	this->_startTime = clock();
}

void Timer::tick(void)
{
	this->_deltaTime = clock();
}

float Timer::getDeltaTime(void)
{
	return (this->_deltaTime - this->_startTime);
}
