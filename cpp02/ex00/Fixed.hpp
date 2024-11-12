/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:54:32 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/11 18:59:55 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__

class Fixed {
public:
	Fixed();
	Fixed(Fixed const &src);
	~Fixed();

	Fixed	&operator=(Fixed const &src);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					_rawBits;
	static const int	_nFractBits;
};

#endif
