/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:37:08 by wpepping          #+#    #+#             */
/*   Updated: 2024/12/11 19:17:16 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_H__
# define __BRAIN_H__

#include <string>

class Brain {
public:
	Brain();
	~Brain();
	Brain(Brain const &src);
	Brain &operator=(Brain const &src);

private:
	std::string _ideas[100];
};

#endif
