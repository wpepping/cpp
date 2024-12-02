/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:35:53 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/02 19:36:06 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void basic_tests(void) {
	std::cout << "-- Basic tests" << std::endl << std::endl;

	ClapTrap ct("My ClapTrap");
	ScavTrap st("My ScavTrap");
	FragTrap ft("My FragTrap");

	ct.attack("My Target");
	ct.takeDamage(5);
	ct.beRepaired(2);

	st.attack("My Target");
	st.takeDamage(5);
	st.beRepaired(2);
	st.guardGate();

	ft.attack("My Target");
	ft.takeDamage(5);
	ft.beRepaired(2);
	ft.highFivesGuys();
}

void more_tests(void) {
	std::cout << "-- More tests" << std::endl << std::endl;

	ClapTrap ct("Copy ClapTrap");
	ScavTrap st("Copy ScavTrap");
	FragTrap ft("Copy FragTrap");
	ClapTrap ct2(ct);
	ScavTrap st2(st);
	FragTrap ft2(ft);
	ClapTrap ct3 = ct2;
	ScavTrap st3 = st2;
	FragTrap ft3 = ft2;

	ct3.attack("My Target");
	ct3.takeDamage(5);
	ct3.beRepaired(2);

	st3.attack("My Target");
	st3.takeDamage(5);
	st3.beRepaired(2);

	ft3.attack("My Target");
	ft3.takeDamage(5);
	ft3.beRepaired(2);
}

int main(void) {
	basic_tests();
	std::cout << std::endl << std::endl;
	more_tests();
}
