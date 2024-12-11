/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:20:03 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/11 18:31:13 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
# define __DOG_H__

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(Dog const &src);
	virtual ~Dog();
	Dog &operator=(Dog const &src);

	virtual void makeSound() const;
};

#endif
