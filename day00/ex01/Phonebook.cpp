/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:40:22 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 12:52:52 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->_empty = true;
	return;
}

Phonebook::~Phonebook()
{
	return;
}

void		Phonebook::add(Phonebook contacts[COUNT_CONTACTS])
{
	int		contact;

	contact = 0;
	while (!contacts[contact]._empty && contact < COUNT_CONTACTS)
		contact++;
	if (contact == COUNT_CONTACTS)
		std::cout << std::endl << "Phonebook is full !!!" << std::endl;
	else
	{
		std::cout << std::endl << "Enter first name: ";
		std::getline(std::cin, contacts[contact]._firstName);
		std::cout << "Enter last name: ";
		std::getline(std::cin, contacts[contact]._lastName);
		std::cout << "Enter nickname: ";
		std::getline(std::cin, contacts[contact]._nickname);
		std::cout << "Enter login: ";
		std::getline(std::cin, contacts[contact]._login);
		std::cout << "Enter postal address: ";
		std::getline(std::cin, contacts[contact]._postalAddress);
		std::cout << "Enter email address: ";
		std::getline(std::cin, contacts[contact]._emailAddress);
		std::cout << "Enter phone number: ";
		std::getline(std::cin, contacts[contact]._phoneNumber);
		std::cout << "Enter birthday date: ";
		std::getline(std::cin, contacts[contact]._birthdayDate);
		std::cout << "Enter favorite meal: ";
		std::getline(std::cin, contacts[contact]._favoriteMeal);
		std::cout << "Enter underwear color: ";
		std::getline(std::cin, contacts[contact]._underwearColor);
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, contacts[contact]._darkestSecret);
		contacts[contact]._empty = false;
	}
}

void		Phonebook::printField(std::string str)
{
	std::cout << "|";
	if (str.size() <= 10)
		std::cout << std::setw(10) << str;
	else
		std::cout << str.substr(0, 9) << ".";
}

void		Phonebook::printContact(Phonebook contacts[COUNT_CONTACTS],
									std::string str)
{
	int		index;
	int		contact;

	if (str.size() == 1 && isdigit(str[0]))
	{
		index = (int)(str[0] - '0');
		if (index > 0 && index <= COUNT_CONTACTS)
		{
			contact = index - 1;
			if (!contacts[contact]._empty)
			{
				std::cout << std::endl << "First name: " << contacts[contact]._firstName << std::endl;
				std::cout << "Last name: " << contacts[contact]._lastName << std::endl;
				std::cout << "Nickname: " << contacts[contact]._nickname << std::endl;
				std::cout << "Login: " << contacts[contact]._login << std::endl;
				std::cout << "Postal address: " << contacts[contact]._postalAddress << std::endl;
				std::cout << "Email address: " << contacts[contact]._emailAddress << std::endl;
				std::cout << "Phone number: " << contacts[contact]._phoneNumber << std::endl;
				std::cout << "Birthday date: " << contacts[contact]._birthdayDate << std::endl;
				std::cout << "Favorite meal: " << contacts[contact]._favoriteMeal << std::endl;
				std::cout << "Underwear color: " << contacts[contact]._underwearColor << std::endl;
				std::cout << "Darkest secret: " << contacts[contact]._darkestSecret << std::endl;
			}
			else
				std::cout << "Wrong index" << std::endl;
		}
		else
			std::cout << "Wrong index" << std::endl;
	}
	else
		std::cout << "Wrong index" << std::endl;
}

void		Phonebook::search(Phonebook contacts[COUNT_CONTACTS])
{
	int		contact;

	contact = 0;
	if (!contacts[contact]._empty)
	{
		std::cout << std::endl;
		std::cout << " ___________________________________________" << std::endl;
		Phonebook::printField("index");
		Phonebook::printField("first name");
		Phonebook::printField("last name");
		Phonebook::printField("nickname");
		std::cout << "|" << std::endl;
		std::cout << " -------------------------------------------" << std::endl;
	}
	while (!contacts[contact]._empty && contact < COUNT_CONTACTS)
	{
		std::cout << "|";
		std::cout << std::setw(10) << (contact + 1);
		Phonebook::printField(contacts[contact]._firstName);
		Phonebook::printField(contacts[contact]._lastName);
		Phonebook::printField(contacts[contact]._nickname);
		std::cout << "|" << std::endl;
		std::cout << " -------------------------------------------" << std::endl;
		contact++;
	}
	if (contact == 0)
		std::cout << std::endl << "Phonebook is empty" << std::endl;
}

std::string		Phonebook::getFirstName( void ) const
{
	return this->_firstName;
}

std::string		Phonebook::getLastName( void ) const
{
	return this->_lastName;
}

std::string		Phonebook::getNickName( void ) const
{
	return this->_nickname;
}

std::string		Phonebook::getLogin( void ) const
{
	return this->_login;
}

std::string		Phonebook::getPostalAddress( void ) const
{
	return this->_postalAddress;
}

std::string		Phonebook::getEmailAddress( void ) const
{
	return this->_emailAddress;
}

std::string		Phonebook::getPhoneNumber( void ) const
{
	return this->_phoneNumber;
}

std::string		Phonebook::getBirthdayDate( void ) const
{
	return this->_birthdayDate;
}

std::string		Phonebook::getFavoriteMeal( void ) const
{
	return this->_favoriteMeal;
}

std::string		Phonebook::getUnderwearColor( void ) const
{
	return this->_underwearColor;
}

std::string		Phonebook::getDarkestSecret( void ) const
{
	return this->_darkestSecret;
}

void			Phonebook::setFirstName( std::string str )
{
	this->_firstName = str;
}

void			Phonebook::setLastName( std::string str )
{
	this->_lastName = str;
}

void			Phonebook::setNickName( std::string str )
{
	this->_nickname = str;
}

void			Phonebook::setLogin( std::string str )
{
	this->_login = str;
}

void			Phonebook::setPostalAddress( std::string str )
{
	this->_postalAddress = str;
}

void			Phonebook::setEmailAddress( std::string str )
{
	this->_emailAddress = str;
}

void			Phonebook::setPhoneNumber( std::string str )
{
	this->_phoneNumber = str;
}

void			Phonebook::setBirthdayDate( std::string str )
{
	this->_birthdayDate = str;
}

void			Phonebook::setFavoriteMeal( std::string str )
{
	this->_favoriteMeal = str;
}

void			Phonebook::setUnderwearColor( std::string str )
{
	this->_underwearColor = str;
}

void			Phonebook::setDarkestSecret( std::string str )
{
	this->_darkestSecret = str;
}
