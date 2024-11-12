/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpepping <wpepping@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:51:12 by wpepping          #+#    #+#             */
/*   Updated: 2024/11/05 19:24:54 by wpepping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

# define CAPACITY 8
# define TABLE_HEADER "| index|     fname|     lname|  nickname|  phone nr|    secret|"
# define SEARCH_PROMPT "Please select contact number to search: "
# define ADD_CONTACT_PROMPT "Adding contact. Please enter details."
# define ERR_NAME_EMPTY "Error: first name and last name cannot be empty."
# define ERR_INVALID_INDEX "Error: invalid index."
# define ERR_CONTACT_LIST_EMPTY "Contact list empty."
# define FIRST_NAME_PROMPT "First name: ";
# define LAST_NAME_PROMPT "Last name: ";
# define NICKNAME_PROMPT "Nickname: ";
# define PHONE_NR_PROMPT "Phone number: ";
# define SECRET_PROMPT "Darkest secret: ";
# define GOODBYE "Goodbye."
# define ADD "ADD"
# define EXIT "EXIT"
# define SEARCH "SEARCH"
# define PROMPT "PhoneBook$ "

class PhoneBook {

private:
	Contact			_contacts[CAPACITY];
	void			_saveContactDetails(Contact c, int pos);
	void			_saveContact(Contact c);
	void			_addContact();
	void			_showContact() const;
	std::string		_formatItem(const std::string &s) const;
	void			_listItem(int i) const;
	void			_list() const;

public:
	PhoneBook();
	void listen();
};

#endif
