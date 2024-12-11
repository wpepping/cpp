/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:15:15 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/11 19:22:32 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
# define __CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(Cat const &src);
	virtual ~Cat();
	Cat &operator=(Cat const &src);

	virtual void makeSound() const;

private:
	Brain *_brain;
};

#endif
