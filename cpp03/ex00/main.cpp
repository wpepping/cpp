/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:35:53 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/27 16:24:35 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap ct("My ClapTrap");

	ct.beRepaired(2);
	ct.takeDamage(5);
	ct.beRepaired(2);
	for (int i = 0; i < 10; i++)
		ct.attack("My Target");
	ct.beRepaired(2);
	ct.takeDamage(4);
	ct.takeDamage(4);
	ct.takeDamage(4);
}
