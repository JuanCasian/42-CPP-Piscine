/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <jcasian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:49:12 by jcasian           #+#    #+#             */
/*   Updated: 2019/05/09 21:01:26 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void	iter(T *arr, int len, void(*f)(T &)) {
	for (int i = 0; i < len; i++) {
		f(arr[i]);
	}
}

template<typename T>
void	printArr(T &data) {
	std::cout << data << " ";
}

void addOne(int &n) {
	n += 1;
}

int main(void) {
	int	intArr[] = {1, 2, 3, 4};
	char charArr[] = {'a', 'b', 'c', 'd'};

	std::cout << "Integer test: " << std::endl;
	iter(intArr, 4, &printArr<int>);
	std::cout << std::endl;
	iter(intArr, 4, &addOne);
	iter(intArr, 4, &printArr<int>);
	std::cout << std::endl;

	std::cout << "Char test: " << std::endl;
	iter(charArr, 4, &printArr<char>);
	std::cout << std::endl;
	return (0);
}