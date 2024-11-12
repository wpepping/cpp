/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:51:25 by wpepping          #+#    #+#             */
/*   Updated: 2024/09/23 15:18:22 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

class Contact {

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNr;
	std::string _secret;

public:
	Contact();
	Contact(std::string firstName, std::string lastName,
		std::string nickname, std::string phoneNr, std::string secret);
	const std::string &getFirstName() const;
	const std::string &getLastName() const;
	const std::string &getNickname() const;
	const std::string &getPhoneNr() const;
	const std::string &getSecret() const;
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string nickname);
	void setPhoneNr(std::string phoneNr);
	void setSecret(std::string secret);
};

#endif
