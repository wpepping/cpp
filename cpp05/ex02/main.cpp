/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:33:05 by wpepping          #+#    #+#             */
/*   Updated: 2025/02/16 16:54:26 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat c("Jimmy", 149);
	Bureaucrat d("Johnny", 2);

	Form f;
	Form g("ApplicationForm", 10, 10);

	std::cout << f << std::endl;
	std::cout << g << std::endl;

	c.signForm(g);
	d.signForm(g);
}
