/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:38:28 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/27 16:37:11 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called." << std::endl;
	_init("", 10, 10, 0);
};

ClapTrap::ClapTrap(const std::string &name) {
	std::cout << "Name constructor called." << std::endl;
	_init(name, 10, 10, 0);
};

ClapTrap::ClapTrap(ClapTrap const &src) {
	std::cout << "Copy constructor called." << std::endl;
	_init(src._name, src._hitPoints, src._energyPoints, src._attackDamage);
};

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called." << std::endl;
};

ClapTrap &ClapTrap::operator=(ClapTrap const &src) {
	this->_init(src._name, src._hitPoints, src._energyPoints, src._attackDamage);
	return (*this);
};

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage." << std::endl;
		_energyPoints--;
	}
	else
		_error();
};

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > _hitPoints)
		amount = _hitPoints;
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage." << std::endl;
	this->_hitPoints -= amount;
};

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && amount > _maxHitPoints - _hitPoints)
	{
		std::cout << "ClapTrap " << _name << " repairs for " << amount
			<< " points." << std::endl;
		this->_hitPoints += amount;
		_energyPoints--;
	}
	else
		_error();
};

void ClapTrap::_init(const std::string &name, unsigned int hit, unsigned int energy, unsigned int attack) {
	this->_name = name;
	this->_hitPoints = hit;
	this->_energyPoints = energy;
	this->_attackDamage = attack;
	this->_maxHitPoints = hit;
};

void ClapTrap::_error() {
	std::cout << "You did something wrong." << std::endl;
};
