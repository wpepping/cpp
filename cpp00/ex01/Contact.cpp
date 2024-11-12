/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:51:31 by wpepping          #+#    #+#             */
/*   Updated: 2024/09/23 15:18:22 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	Contact("", "", "", "", "");
};

Contact::Contact(std::string firstName, std::string lastName,
		std::string nickname, std::string phoneNr, std::string secret) {
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNr = phoneNr;
	this->_secret = secret;
}

const std::string	&Contact::getFirstName() const {
	return this->_firstName;
}

const std::string	&Contact::getLastName() const {
	return this->_lastName;
}

const std::string	&Contact::getNickname() const {
	return this->_nickname;
}

const std::string	&Contact::getPhoneNr() const {
	return this->_phoneNr;
}

const std::string	&Contact::getSecret() const {
	return this->_secret;
}

void Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

void Contact::setPhoneNr(std::string phoneNr) {
	this->_phoneNr = phoneNr;
}

void Contact::setSecret(std::string secret) {
	this->_secret = secret;
}
