/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:13:58 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/17 16:31:22 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed f = Fixed(2.2f);
	Fixed g = f;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << (f > b?"true":"false") << std::endl;
	std::cout << (f < b?"true":"false") << std::endl;
	std::cout << (f >= b?"true":"false") << std::endl;
	std::cout << (f <= b?"true":"false") << std::endl;
	std::cout << (f == b?"true":"false") << std::endl;
	std::cout << (f != b?"true":"false") << std::endl;
	std::cout << (f > g?"true":"false") << std::endl;
	std::cout << (f < g?"true":"false") << std::endl;
	std::cout << (f >= g?"true":"false") << std::endl;
	std::cout << (f <= g?"true":"false") << std::endl;
	std::cout << (f == g?"true":"false") << std::endl;
	std::cout << (f != g?"true":"false") << std::endl;

	g = f + b;
	std::cout << g << std::endl;
	g = g - b;
	std::cout << g << std::endl;
	g = g * Fixed(2);
	std::cout << g << std::endl;
	g = g / Fixed(2);
	std::cout << g << std::endl;

	std::cout << g-- << std::endl;
	g++;
	std::cout << --g << std::endl;

	return (0);
}
