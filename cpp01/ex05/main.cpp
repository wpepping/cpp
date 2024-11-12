/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:22:05 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/10 18:59:31 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
	Harl	harl;
	std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "TEST"};

	for (int i = 0; i < 5; i++)
		harl.complain(levels[i]);
}
