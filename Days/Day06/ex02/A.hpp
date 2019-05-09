/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:49:41 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/08 22:52:20 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef A_HPP
 #define A_HPP
 
 #include <iostream>
 #include <string>
 #include "Base.hpp"

 class A : public Base {
 
 public:
	 /* Constructors */
	 A(void);
	 A(A const &src);
 
	 /* Destructor */
	 virtual ~A(void);
 
	 /* Operators */
	 A	&operator=(A const &);
 
	 /* Getters and setters */
 
	 /* Other */
 
 protected:
 
 private:
 };
 
 #endif
 