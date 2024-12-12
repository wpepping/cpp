/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:27:22 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/12 18:02:12 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src) {
	this->type = src.type;
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

Cat &Cat::operator=(Cat const &src) {
	if (this != &src)
		this->type = src.type;
	std::cout << "Cat assignment operator called." << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat meows." << std::endl;
}
