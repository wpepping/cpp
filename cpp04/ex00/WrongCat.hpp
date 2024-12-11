/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:15:15 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/11 16:05:50 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_H__
# define __WRONGCAT_H__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(WrongCat const &src);
	virtual ~WrongCat();
	WrongCat &operator=(WrongCat const &src);

	void makeSound() const;
};

#endif
