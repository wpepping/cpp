/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:22:23 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/10 19:21:28 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
# define __HARL_H__

# include <string>

class Harl {
public:
	Harl();
	~Harl();
	void complain( std::string level ) const ;
	void filteredCompain( std::string level, int filter );
	void setFilter( std::string level );

private:
	int			_filter;
	std::string	_levels[4];
	void 		(Harl::*_functions[4])(void) const;

	int _levelToInt( std::string level ) const;
	void _debug( void ) const ;
	void _info( void ) const ;
	void _warning( void ) const ;
	void _error( void ) const ;
};

#endif
