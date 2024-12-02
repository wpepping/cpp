/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:58:16 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/29 15:33:02 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default FragTrap", 100, 100, 30) {
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap name constructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " really wants a high fives from everyone." << std::endl;
}

void FragTrap::attack(const std::string& target) {
	int attackDamage = _attack();

	if (attackDamage > -1)
		std::cout << "FragTrap " << _name << " attacks " << target
			<< ", causing " << attackDamage << " points of damage." << std::endl;
	else
		_error();
};

void FragTrap::takeDamage(unsigned int amount) {
	std::cout << "FragTrap " << _name << " takes " << _takeDamage(amount)
		<< " points of damage." << std::endl;
};

void FragTrap::beRepaired(unsigned int amount) {
	if (_beRepaired(amount))
		std::cout << "FragTrap " << _name << " repairs for " << amount
			<< " points." << std::endl;
	else
		_error();
};
