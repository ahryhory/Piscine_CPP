/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 20:36:22 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 20:36:23 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name)
{
}

HumanA::~HumanA()
{
}

Weapon			HumanA::getWeapon( void )
{
	return (this->_weapon);
}

std::string		HumanA::getName( void )
{
	return (this->_name);
}

void			HumanA::setName( std::string name )
{
	this->_name = name;
}

void			HumanA::attack( void )
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
