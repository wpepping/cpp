/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:15:15 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/11 18:31:10 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
# define __CAT_H__

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(Cat const &src);
	virtual ~Cat();
	Cat &operator=(Cat const &src);

	virtual void makeSound() const;
};

#endif
