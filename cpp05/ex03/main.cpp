/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:05 by wpepping          #+#    #+#             */
/*   Updated: 2025/02/17 15:06:25 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Bureaucrat c("Johnny", 60);

	Intern i;
	AForm *f;

	f = PresidentialPardonForm::create("test");
	delete f;
	f = i.makeForm("presidential pardon", "test");
	c.signForm(*f);
	c.executeForm(*f);
	delete f;
	f = i.makeForm("robotomy request", "test");
	c.signForm(*f);
	c.executeForm(*f);
	delete f;
	f = i.makeForm("shrubbery creation", "test");
	c.signForm(*f);
	c.executeForm(*f);
	delete f;
	i.makeForm("dolphin treat request", "");
}
