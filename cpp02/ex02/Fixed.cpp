/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:45:21 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/17 16:26:34 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n) : _rawBits(n << Fixed::_nFractBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float f) : _rawBits(f * pow(2, Fixed::_nFractBits) + 0.5) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = src.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &src) {
	return (this->_rawBits > src._rawBits);
}

bool	Fixed::operator<(Fixed const &src) {
	return (this->_rawBits < src._rawBits);
}

bool	Fixed::operator>=(Fixed const &src) {
	return (this->_rawBits >= src._rawBits);
}

bool	Fixed::operator<=(Fixed const &src) {
	return (this->_rawBits <= src._rawBits);
}

bool	Fixed::operator==(Fixed const &src) {
	return (this->_rawBits == src._rawBits);
}

bool	Fixed::operator!=(Fixed const &src) {
	return (this->_rawBits != src._rawBits);
}

Fixed	Fixed::operator+(Fixed const &src) {
	Fixed result;

	result._rawBits = this->_rawBits + src._rawBits;
	return (result);
}

Fixed	Fixed::operator-(Fixed const &src) {
	Fixed result;

	result._rawBits = this->_rawBits - src._rawBits;
	return (result);
}


Fixed	Fixed::operator*(Fixed const &src) {
	Fixed result;

	result._rawBits = (this->_rawBits * src._rawBits) >> Fixed::_nFractBits;
	return (result);
}


Fixed	Fixed::operator/(Fixed const &src) {
	Fixed result;

	result._rawBits = (this->_rawBits << Fixed::_nFractBits) / src._rawBits;
	return (result);
}

Fixed	&Fixed::operator++() {
	this->_rawBits++;
	return (*this);
}

Fixed	&Fixed::operator--() {
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed old;

	old = *this;
	this->_rawBits++;
	return (old);
}

Fixed	Fixed::operator--(int) {
	Fixed old;

	old = *this;
	this->_rawBits--;
	return (old);
}

std::ostream	&operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return (os);
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
}

int		Fixed::toInt( void ) const {
	return (this->_rawBits >> Fixed::_nFractBits);
}

float	Fixed::toFloat( void ) const {
	return (1.0 * this->_rawBits / pow(2, Fixed::_nFractBits));
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs) {
	if (rhs._rawBits < lhs._rawBits)
		return (rhs);
	return (lhs);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs) {
	if (rhs._rawBits > lhs._rawBits)
		return (rhs);
	return (lhs);
}

Fixed const	&Fixed::min(Fixed const &lhs, Fixed const &rhs) {
	if (rhs._rawBits < lhs._rawBits)
		return (rhs);
	return (lhs);
}

Fixed const	&Fixed::max(Fixed const &lhs, Fixed const &rhs) {
	if (rhs._rawBits > lhs._rawBits)
		return (rhs);
	return (lhs);
}
