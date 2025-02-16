/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:05 by wpepping          #+#    #+#             */
/*   Updated: 2025/02/11 18:53:54 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	const 	Animal* meta 	= new Animal();
	const 	Animal* j 		= new Dog();
	const 	Animal* i 		= new Cat();
	const	Cat* c			= new Cat();
	Animal	*animals[100];

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

	((Cat *)i)->getBrain()->setIdea(0, "Love is just a chemical reaction in the brain.");
	const Cat a(*((const Cat *)i));
	std::cout << "-- Create cat b" << std::endl;
	Cat b = *c;
	std::cout << "-- Done creating cat b" << std::endl;
	std::cout << "-- Create cat d" << std::endl;
	Cat d;
	d = *(Cat *)i;
	std::cout << "-- Done creating cat d" << std::endl;
	Cat e;

	std::cout << std::endl;

	a.getBrain()->setIdea(0, "Life is life.");
	std::cout << "Idea of i: " << ((Cat *)i)->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea of a: " << a.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete c;

	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete animals[i];

	return 0;
}
