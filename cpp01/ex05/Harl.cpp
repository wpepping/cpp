/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 224/11/10 18:22:55 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/10 18:34:42 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";
	_functions[0] = &Harl::_debug;
	_functions[1] = &Harl::_info;
	_functions[2] = &Harl::_warning;
	_functions[3] = &Harl::_error;
}

Harl::~Harl() {
}

int Harl::_levelToInt( std::string level ) const {
	for (int i = 0; i < 4; i++)
	{
		if (_levels[i] == level)
			return (i);
	}
	return (-1);
}

void Harl::complain( std::string level ) const {
	int level_n;

	level_n = _levelToInt(level);
	if (level_n > -1)
		(this->*_functions[level_n])();
	else
		std::cout << "Harl is confused." << std::endl;
}

void Harl::_debug( void ) const {
	std::cout << "I love having extra bacon for my 7XL-double-cheese"
		<< "-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void Harl::_info( void ) const {
	std::cout << "I cannot believe adding extra bacon costs more money."
		<< " You didn’t put enough bacon in my burger! If you did, I wouldn’t"
		<< " be asking for more!"
		<< std::endl;
}

void Harl::_warning( void ) const {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been"
		<< " coming for years whereas you started working here since last month."
		<< std::endl;
}

void Harl::_error( void ) const {
	std::cout << "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}
