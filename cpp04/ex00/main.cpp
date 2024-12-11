/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:05 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/11 18:35:29 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	((const Cat *)i)->makeSound();
	((const Dog *)j)->makeSound();

	std::cout << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound();
	meta2->makeSound();
	((const WrongCat *)i2)->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete meta2;
	delete i2;

	return 0;
}
