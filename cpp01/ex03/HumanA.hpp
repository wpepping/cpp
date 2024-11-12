/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:18:12 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/10 16:19:38 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
# define __HUMANA_H__

# include "Weapon.hpp"
# include "iostream"

class HumanA {
public:
	Weapon *_weapon;
	std::string _name;

public:
	HumanA();
	HumanA(std::string name, Weapon &weapon);
	void attack() const;
};

#endif
