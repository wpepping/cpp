/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:14:39 by wpepping          #+#    #+#             */
/*   Updated: 2025/02/06 17:08:03 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_H__
# define __ANIMAL_H__

#include <string>

class Animal {
public:
	Animal();
	Animal(Animal const &src);
	virtual ~Animal();
	Animal &operator=(Animal const &src);

	std::string getType() const;
	virtual void makeSound() const;

protected:
	 std::string type;
};

#endif
