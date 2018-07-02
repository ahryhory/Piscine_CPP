/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 20:37:38 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 20:37:38 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::HumanB()
{
}

HumanB::~HumanB()
{
}

Weapon			HumanB::getWeapon( void )
{
	return (*this->_weapon);
}

void			HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
}

std::string		HumanB::getName( void )
{
	return (this->_name);
}

void			HumanB::setName( std::string name )
{
	this->_name = name;
}

void			HumanB::attack( void )
{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
