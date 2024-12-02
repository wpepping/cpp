/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:38:28 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/29 15:32:45 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called." << std::endl;
	_init("Default ClapTrap", 10, 10, 0);
};

ClapTrap::ClapTrap(const std::string &name) {
	std::cout << "Name constructor called." << std::endl;
	_init(name, 10, 10, 0);
};

ClapTrap::ClapTrap(const std::string &name, unsigned int hit, unsigned int energy, unsigned int attack) {
	std::cout << "Name constructor called." << std::endl;
	_init(name, hit, energy, attack);
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
	int attackDamage = _attack();

	if (attackDamage > -1)
		std::cout << "ClapTrap " << _name << " attacks " << target
			<< ", causing " << attackDamage << " points of damage." << std::endl;
	else
		_error();
};

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " takes " << _takeDamage(amount)
		<< " points of damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_beRepaired(amount))
		std::cout << "ClapTrap " << _name << " repairs for " << amount
			<< " points." << std::endl;
	else
		_error();
};

int	ClapTrap::_attack() {
	if (_energyPoints > 0)
	{
		_energyPoints--;
		return (_attackDamage);
	}
	else
		return (-1);
};

int		ClapTrap::_takeDamage(unsigned int amount) {
	if (amount > _hitPoints)
		amount = _hitPoints;
	this->_hitPoints -= amount;
	return (amount);
};

bool	ClapTrap::_beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && amount <= _maxHitPoints - _hitPoints)
	{
		this->_hitPoints += amount;
		_energyPoints--;
		return (true);
	}
	return (false);
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
