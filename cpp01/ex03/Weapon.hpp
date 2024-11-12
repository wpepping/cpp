/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:59:59 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/10 16:19:17 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
# define __WEAPON_H__

# include <string>

class Weapon {
private:
	std::string _type;
	void init(std::string type);

public:
	Weapon(void);
	Weapon(std::string type);
	const std::string &getType(void) const;
	void setType(std::string type);
};

#endif
