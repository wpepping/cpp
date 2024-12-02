/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:58:16 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/29 15:33:10 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default ScavTrap", 100, 50, 20) {
	std::cout << "ScavTrap default constructor called." << std::endl;
};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap name constructor called." << std::endl;
};

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called." << std::endl;
};

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called." << std::endl;
};

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
};

void ScavTrap::attack(const std::string& target) {
	int attackDamage = _attack();

	if (attackDamage > -1)
		std::cout << "ScavTrap " << _name << " attacks " << target
			<< ", causing " << attackDamage << " points of damage." << std::endl;
	else
		_error();
};

void ScavTrap::takeDamage(unsigned int amount) {
	std::cout << "ScavTrap " << _name << " takes " << _takeDamage(amount)
		<< " points of damage." << std::endl;
};

void ScavTrap::beRepaired(unsigned int amount) {
	if (_beRepaired(amount))
		std::cout << "ScavTrap " << _name << " repairs for " << amount
			<< " points." << std::endl;
	else
		_error();
};
