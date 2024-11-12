/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:17:02 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/10 16:20:49 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

void Weapon::init(std::string type) {
	this->_type = type;
}

Weapon::Weapon(void) {
	init("");
}

Weapon::Weapon(std::string type) {
	init(type);
}

const std::string &Weapon::getType(void) const {
	return (this->_type);
}

void Weapon::setType(std::string type) {
	this->_type = type;
}
