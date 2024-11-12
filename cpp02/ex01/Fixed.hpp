/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:54:32 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/11 20:01:22 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__

class Fixed {
public:
	Fixed();
	Fixed(int n);
	Fixed(float f);
	Fixed(Fixed const &src);
	~Fixed();

	Fixed	&operator=(Fixed const &src);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;

private:
	int					_rawBits;
	static const int	_nFractBits = 8;
};

#endif
