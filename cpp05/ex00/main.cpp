/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:05 by wpepping          #+#    #+#             */
/*   Updated: 2025/02/16 16:32:46 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat b;
	Bureaucrat c("Jimmy", 149);
	Bureaucrat d("Johnny", 2);

	try {
		Bureaucrat bb("James", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat cc("Jeanet", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		c.decrementGrade();
		c.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		d.incrementGrade();
		d.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat dd;
	dd = d;

	std::cout << "Bureaucrat b: " << b << " (should be name=\"\" grade=150)" << std::endl;
	std::cout << "Bureaucrat c: " << c << " (should be name=Jimmy grade=150)" << std::endl;
	std::cout << "Bureaucrat dd: " << dd << " (should be name=\"\" grade=1)" << std::endl;
}
