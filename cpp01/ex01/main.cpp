/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:14:04 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/06 20:42:51 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );


int main(void) {
	int nr_of_zombies = 4;
	Zombie *horde;

	horde = zombieHorde(nr_of_zombies, "testzombie");
	for (int i = 0; i < nr_of_zombies; i++) {
		horde->announce();
		horde->~Zombie();
	}
	return (0);
}
