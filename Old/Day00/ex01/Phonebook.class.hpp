/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:19:42 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/21 20:19:44 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "crappy_phonebook.hpp"

class Phonebook {
public:
	Phonebook(void);
	~Phonebook(void);
	void add_contact(void);
	void search_contact(void) const;
private:
	Contact	contacts[8];
	int		nb_contacts;
};

#endif
