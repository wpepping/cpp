/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:27:22 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/12 17:10:16 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    std::cout << "Cat default constructor called." << std::endl;
    type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal(src) {
	this->_brain = new Brain(*src._brain);
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
	delete _brain;
}

Cat &Cat::operator=(Cat const &src) {
	std::cout << "Cat assignment operator called." << std::endl;
    if (this != &src)
	{
        this->type = src.type;
		this->_brain = new Brain(*src._brain);
	}
    return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat meows." << std::endl;
}

Brain *Cat::getBrain() const {
	return _brain;
}
