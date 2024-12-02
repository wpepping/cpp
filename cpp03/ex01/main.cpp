/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:35:53 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/29 15:00:40 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void basic_tests(void) {
	std::cout << "-- Basic tests" << std::endl << std::endl;

	ClapTrap ct("My ClapTrap");
	ScavTrap st("My ScavTrap");

	ct.attack("My Target");
	ct.takeDamage(5);
	ct.beRepaired(2);

	st.attack("My Target");
	st.takeDamage(5);
	st.beRepaired(2);
	st.guardGate();
}

void more_tests(void) {
	std::cout << "-- More tests" << std::endl << std::endl;

	ClapTrap ct("Copy ClapTrap");
	ScavTrap st("Copy ScavTrap");
	ClapTrap ct2(ct);
	ScavTrap st2(st);
	ClapTrap ct3 = ct2;
	ScavTrap st3 = st2;

	ct3.attack("My Target");
	ct3.takeDamage(5);
	ct3.beRepaired(2);

	st3.attack("My Target");
	st3.takeDamage(5);
	st3.beRepaired(2);
}

int main(void) {
	basic_tests();
	std::cout << std::endl << std::endl;
	more_tests();
}
