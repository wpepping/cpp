/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:20:22 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/12 18:01:58 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	type = "";
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(Animal const &src) {
	this->type = src.type;
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

Animal &Animal::operator=(Animal const &src) {
	if (this != &src)
		this->type = src.type;
	std::cout << "Animal assignment operator called." << std::endl;
	return *this;
}

std::string Animal::getType() const {
	return (type);
}

void Animal::makeSound() const {
	std::cout << "Animal makes some generic sound." << std::endl;
}
