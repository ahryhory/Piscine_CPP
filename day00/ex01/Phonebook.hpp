/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:40:15 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/18 14:40:18 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define COUNT_CONTACTS 8
# include <string>
# include <iostream>
# include <iomanip>

class Phonebook
{

public:

	Phonebook();
	~Phonebook();
	static void		add(Phonebook contacts[COUNT_CONTACTS]);
	static void		search(Phonebook contacts[COUNT_CONTACTS]);
	static void		printField(std::string str);
	static void		printContact(Phonebook contacts[COUNT_CONTACTS],
									std::string index);
	std::string		getFirstName( void ) const;
	std::string		getLastName( void ) const;
	std::string		getNickName( void ) const;
	std::string		getLogin( void ) const;
	std::string		getPostalAddress( void ) const;
	std::string		getEmailAddress( void ) const;
	std::string		getPhoneNumber( void ) const;
	std::string		getBirthdayDate( void ) const;
	std::string		getFavoriteMeal( void ) const;
	std::string		getUnderwearColor( void ) const;
	std::string		getDarkestSecret( void ) const;

	void			setFirstName( std::string str );
	void			setLastName( std::string str );
	void			setNickName( std::string str );
	void			setLogin( std::string str );
	void			setPostalAddress( std::string str );
	void			setEmailAddress( std::string str );
	void			setPhoneNumber( std::string str );
	void			setBirthdayDate( std::string str );
	void			setFavoriteMeal( std::string str );
	void			setUnderwearColor( std::string str );
	void			setDarkestSecret( std::string str );

private:

	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickname;
	std::string		_login;
	std::string		_postalAddress;
	std::string		_emailAddress;
	std::string		_phoneNumber;
	std::string		_birthdayDate;
	std::string		_favoriteMeal;
	std::string		_underwearColor;
	std::string		_darkestSecret;
	bool			_empty;

};

#endif
