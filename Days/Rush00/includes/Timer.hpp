/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:57:52 by csinglet          #+#    #+#             */
/*   Updated: 2019/05/05 18:57:52 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_HPP
# define TIMER_HPP

# include <time.h>

class Timer
{
	private:
		clock_t _startTime;
		clock_t _deltaTime;

	public:
		Timer(void);
		Timer(Timer const &);
		~Timer(void);
		// Operator
		Timer & operator=(Timer const &);
		// Methods
		void resetStartTime(void);
		void tick(void);
		// Setters
		// Getters
		float getDeltaTime(void);
};

#endif
