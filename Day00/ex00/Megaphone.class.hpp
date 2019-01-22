/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:21:03 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 16:41:38 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_CLASS_HPP

# define MEGAPHONE_CLASS_HPP



class Megaphone {

	public:
		Megaphone(int ac, char **av);
		~Megaphone(void);

		void		makeNoise(void) const;
		static char	to_uppercase(char c);

	private:
		int		ac;
		char	**av;
};

#endif
