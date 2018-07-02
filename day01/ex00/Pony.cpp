/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:54:50 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 12:54:51 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony( void )
{
	std::cout << std::endl << "Pony was created" << std::endl;
}

Pony::~Pony( void )
{
	std::cout << "Pony was deleted" << std::endl;
}

int				Pony::getAge( void ) const
{
	return (this->_age);
}

std::string		Pony::getName( void ) const
{
	return (this->_name);
}

void			Pony::setAge(int age)
{
	if (age > 0)
		this->_age = age;
}

void			Pony::setName(std::string name)
{
	if (name != "")
		this->_name = name;
}
