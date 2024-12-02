/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:45:21 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/21 17:28:13 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _rawBits(n << Fixed::_nFractBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _rawBits(f * pow(2, Fixed::_nFractBits) + 0.5) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = src.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return (os);
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

int Fixed::toInt( void ) const {
	return (this->_rawBits >> Fixed::_nFractBits);
}

float Fixed::toFloat( void ) const {
	return (1.0 * this->_rawBits / pow(2, Fixed::_nFractBits));
}
