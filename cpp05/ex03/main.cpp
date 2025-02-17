/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:05 by wpepping          #+#    #+#             */
/*   Updated: 2025/02/16 19:19:32 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat c("Jimmy", 140);
	Bureaucrat d("Johnny", 60);
	Bureaucrat e("James", 10);
	Bureaucrat f("Zaphod Beeblebrox", 1);

	PresidentialPardonForm p;
	PresidentialPardonForm o("meeeee");

	std::cout << p << std::endl;
	std::cout << o << std::endl;

	c.signForm(o);
	f.executeForm(o);
	e.signForm(o);
	e.executeForm(o);
	f.executeForm(o);

	std::cout << std::endl;

	RobotomyRequestForm r("Arthur Dent");
	c.signForm(r);
	f.executeForm(r);
	d.signForm(r);
	d.executeForm(r);
	e.executeForm(r);

	std::cout << std::endl;

	ShrubberyCreationForm s("Shrubber");
	f.executeForm(s);
	c.signForm(s);
	c.executeForm(s);
	d.executeForm(s);
}
