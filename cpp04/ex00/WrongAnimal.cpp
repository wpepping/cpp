/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:20:22 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/11 16:03:30 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
    type = "";
    std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
    this->type = src.type;
    std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) {
    if (this != &src)
        this->type = src.type;
    std::cout << "WrongAnimal assignment operator called." << std::endl;
    return *this;
}

std::string WrongAnimal::getType() const {
	return (type);
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes some generic sound." << std::endl;
}
