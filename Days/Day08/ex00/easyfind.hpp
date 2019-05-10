/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:53:57 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/10 16:41:49 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm> 
#include <iostream> 
#include <vector>

template<typename T>
typename T::iterator	easyfind(T &cont, int val) {
	return (std::find(cont.begin(), cont.end(), val));
}