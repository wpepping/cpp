/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:20:22 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/12 17:20:55 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called." << std::endl;
}

std::string AAnimal::getType() const {
	return (type);
}
