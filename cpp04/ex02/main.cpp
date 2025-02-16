/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:05 by wpepping          #+#    #+#             */
/*   Updated: 2025/02/06 17:13:31 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	((const Cat *)i)->makeSound();
	((const Dog *)j)->makeSound();

	std::cout << std::endl;

	((Cat *)i)->getBrain()->setIdea(0, "Love is just a chemical reaction in the brain.");
	const Cat a(*((const Cat *)i));

	std::cout << std::endl;

	a.getBrain()->setIdea(0, "Life is life.");
	std::cout << "Idea of i: " << ((Cat *)i)->getBrain()->getIdea(0) << std::endl;
	std::cout << "Idea of a: " << a.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;

	delete j;
	delete i;

	return 0;
}
