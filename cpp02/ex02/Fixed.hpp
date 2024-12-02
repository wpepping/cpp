/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:54:32 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/21 17:33:38 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(int n);
	Fixed(float f);
	Fixed(Fixed const &src);
	~Fixed();

	Fixed	&operator=(Fixed const &src);

	bool	operator>(Fixed const &src) const;
	bool	operator<(Fixed const &src) const;
	bool	operator>=(Fixed const &src) const;
	bool	operator<=(Fixed const &src) const;
	bool	operator==(Fixed const &src) const;
	bool	operator!=(Fixed const &src) const;

	Fixed	operator+(Fixed const &src);
	Fixed	operator-(Fixed const &src);
	Fixed	operator*(Fixed const &src);
	Fixed	operator/(Fixed const &src);

	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;

	static Fixed		&min(Fixed &lhs, Fixed &rhs);
	static Fixed		&max(Fixed &lhs, Fixed &rhs);
	static Fixed const	&min(Fixed const &lhs, Fixed const &rhs);
	static Fixed const	&max(Fixed const &lhs, Fixed const &rhs);

private:
	int					_rawBits;
	static const int	_nFractBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed &f);

#endif
