/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:02:45 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/12 18:08:01 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain default constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = "";
	}
}

Brain::Brain(Brain const &src) {
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = src._ideas[i];
	}
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

Brain &Brain::operator=(Brain const &src) {
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		{
			_ideas[i] = src._ideas[i];
		}
	}
	std::cout << "Brain assignment operator called." << std::endl;
	return *this;
}

std::string Brain::getIdea(int i) const {
	return _ideas[i];
}

void Brain::setIdea(int i, std::string idea) {
	_ideas[i] = idea;
}
