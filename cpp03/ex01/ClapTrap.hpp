/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:33:14 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/27 16:53:08 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

#include <string>
#include <iostream>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const std::string &name, unsigned int hit, unsigned int energy, unsigned int attack);
	ClapTrap(ClapTrap const &src);
	~ClapTrap();

	ClapTrap	&operator=(ClapTrap const &src);
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

protected:
	std::string		_name;

	int		_attack();
	int		_takeDamage(unsigned int amount);
	bool	_beRepaired(unsigned int amount);
	void	_error();

private:
	unsigned int	_attackDamage;
	unsigned int	_energyPoints;
	unsigned int	_hitPoints;
	unsigned int	_maxHitPoints;

	void 		_init(const std::string &name, unsigned int hit, unsigned int energy, unsigned int attack);
};

#endif
