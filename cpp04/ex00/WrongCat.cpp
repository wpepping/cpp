/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:27:22 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/11 16:04:00 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src) {
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &src) {
	if (this != &src)
		this->type = src.type;
	std::cout << "WrongCat assignment operator called." << std::endl;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat meows." << std::endl;
}
