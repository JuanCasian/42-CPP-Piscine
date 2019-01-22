/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:42:55 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 19:31:59 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_CLASS_HPP

# define PHONEBOOK_CLASS_HPP

# include <string>

class Phonebook {
	public:
		Phonebook(void);
		~Phonebook(void);

		void	add_contact(void);
		void	search_contact(void) const;
		
	private:
		std::string	contacts[8];
		int			contacts_added;
};

#endif
