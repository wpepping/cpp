/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:14:39 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/12 17:15:41 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_H__
# define __AANIMAL_H__

#include <string>

class AAnimal {
public:
	virtual ~AAnimal();

	std::string getType() const;
	virtual void makeSound() const = 0;

protected:
	 std::string type;
};

#endif
