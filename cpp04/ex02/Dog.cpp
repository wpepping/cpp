/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:29:50 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/12 17:21:05 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    std::cout << "Dog default constructor called." << std::endl;
    type = "Dog";
	_brain = new Brain();
}

Dog::Dog(Dog const &src) : AAnimal(src) {
	this->_brain = new Brain(*src._brain);
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called." << std::endl;
	delete _brain;
}

Dog &Dog::operator=(Dog const &src) {
    std::cout << "Dog assignment operator called." << std::endl;
    if (this != &src)
	{
        this->type = src.type;
		this->_brain = new Brain(*src._brain);
	}
    return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog barks." << std::endl;
}

Brain *Dog::getBrain() const {
	return _brain;
}

