/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:14:39 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/11 15:55:27 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_H__
# define __WRONGANIMAL_H__

#include <string>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &src);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(WrongAnimal const &src);

	std::string getType() const;
	void makeSound() const;

protected:
	 std::string type;
};

#endif
