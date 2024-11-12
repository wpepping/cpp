/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:22:05 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/10 19:15:52 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl		harl;
	std::string	levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "TEST"};

	if (argc < 2)
		harl.setFilter("");
	else
		harl.setFilter(argv[1]);

	for (int i = 0; i < 5; i++)
		harl.complain(levels[i]);
}
