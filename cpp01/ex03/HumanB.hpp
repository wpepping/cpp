/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:38:05 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/10 16:19:32 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
# define __HUMANB_H__

# include "Weapon.hpp"
# include "iostream"

class HumanB {
private:
	Weapon *_weapon;
	std::string _name;

public:
	HumanB();
	HumanB(std::string name);
	void attack() const;
	void setWeapon(Weapon &weapon);
};

#endif
