/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:10:29 by jcasian           #+#    #+#             */
/*   Updated: 2019/04/30 15:43:51 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "crappy_phonebook.hpp"

class Phonebook {

public:
	/* Constructors & Destructors */
	Phonebook(void);
	~Phonebook(void);
	
	/* Setters */
	void	set_contact(Contact contact);

	/* Getters */
	Contact	get_contact(int n) const;

	void	search_contact(void) const;
	void	add_contact(void);

private:
	Contact _contacts[8];
	int		_nb_contacts;
};

#endif