/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:29:50 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/12 18:03:17 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src) {
	this->type = src.type;
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

Dog &Dog::operator=(Dog const &src) {
	if (this != &src)
		this->type = src.type;
	std::cout << "Dog assignment operator called." << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog barks." << std::endl;
}
