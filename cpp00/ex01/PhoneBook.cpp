/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:23:24 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/05 19:33:06 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::_saveContactDetails(Contact c, int pos) {
	_contacts[pos].setFirstName(c.getFirstName());
	_contacts[pos].setLastName(c.getLastName());
	_contacts[pos].setNickname(c.getNickname());
	_contacts[pos].setPhoneNr(c.getPhoneNr());
	_contacts[pos].setSecret(c.getSecret());
}

void PhoneBook::_saveContact(Contact c) {
	for (int i = 0; i < CAPACITY; i++) {
		if (_contacts[i].getFirstName().compare("") == 0) {
			_saveContactDetails(c, i);
			return ;
		}
	}
	for (int i = 0; i < CAPACITY - 1; i++) {
		_contacts[i] = _contacts[i + 1];
	}
	_saveContactDetails(c, CAPACITY - 1);
}

void PhoneBook::_addContact() {
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNr;
	std::string	secret;

	std::cout << ADD_CONTACT_PROMPT << std::endl;
	std::cout << FIRST_NAME_PROMPT;
	std::getline(std::cin, firstName);
	std::cout << LAST_NAME_PROMPT;
	std::getline(std::cin, lastName);
	std::cout << NICKNAME_PROMPT;
	std::getline(std::cin, nickname);
	std::cout << PHONE_NR_PROMPT;
	std::getline(std::cin, phoneNr);
	std::cout << SECRET_PROMPT;
	std::getline(std::cin, secret);
	if (firstName.compare("") == 0 || lastName.compare("") == 0)
		std::cout << ERR_NAME_EMPTY << std::endl;
	else
		_saveContact(Contact(firstName, lastName, nickname, phoneNr,
			secret));
}

std::string PhoneBook::_formatItem(const std::string &s) const {
	if (s.length() > 10)
		return s.substr(0, 9).append(".");
	else
		return s;
}

void PhoneBook::_listItem(int i) const {
	std::cout << '|';
	std::cout << "     " << i;
	std::cout << '|';
	std::cout << std::setw(10) << std::right
		<< _formatItem(_contacts[i].getFirstName());
	std::cout << '|';
	std::cout << std::setw(10) << std::right
		<< _formatItem(_contacts[i].getLastName());
	std::cout << '|';
	std::cout << std::setw(10) << std::right
		<< _formatItem(_contacts[i].getNickname());
	std::cout << '|';
	std::cout << std::setw(10) << std::right
		<< _formatItem(_contacts[i].getPhoneNr());
	std::cout << '|';
	std::cout << std::setw(10) << std::right
		<< _formatItem(_contacts[i].getSecret());
	std::cout << '|' << std::endl;
}

void PhoneBook::_list() const {
	std::cout << std::string(63, '-') << std::endl;
	std::cout << TABLE_HEADER << "\n";
	std::cout << std::string(63, '-') << std::endl;
	for (int i = 0; i < CAPACITY; i++) {
		if (_contacts[i].getFirstName() != "") {
			_listItem(i);
		}
	}
	if (_contacts[0].getFirstName() != "")
		std::cout << std::string(63, '-') << std::endl;
}

void PhoneBook::_showContact() const {
	std::string	index;
	int			i;

	_list();
	if (_contacts[0].getFirstName() == "")
	{
			std::cout << ERR_CONTACT_LIST_EMPTY << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << SEARCH_PROMPT;
	std::cin >> index;
	std::cin.ignore(1, '\n');
	if (index.length() == 1 && index[0] >= '0' && index[0] <= '7') {
		i = index[0] - '0';
		std::cout << std::setw(16) << std::left << "First name: "
			<< _contacts[i].getFirstName() << std::endl;
		std::cout << std::setw(16) << std::left << "Last name: "
			<< _contacts[i].getLastName() << std::endl;
		std::cout << std::setw(16) << std::left << "Nickname: "
			<< _contacts[i].getNickname() << std::endl;
		std::cout << std::setw(16) << std::left << "Phone number: "
			<< _contacts[i].getPhoneNr() << std::endl;
		std::cout << std::setw(16) << std::left << "Darkest secret: "
			<< _contacts[i].getSecret() << std::endl;
	}
	else
		std::cout << ERR_INVALID_INDEX << std::endl;
}

PhoneBook::PhoneBook() {
}

void PhoneBook::listen() {
	std::string cmd = "";
	while (cmd != EXIT)
	{
		std::cout << PROMPT;
		std::getline(std::cin, cmd);
		if (cmd.compare(ADD) == 0)
			_addContact();
		else if (cmd.compare(SEARCH) == 0)
			_showContact();
	}
	std::cout << GOODBYE << std::endl;
}
