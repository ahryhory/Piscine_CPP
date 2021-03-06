/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:10:03 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/19 15:10:04 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "Mr. Dead";
}

Zombie::Zombie(std::string name, std::string type)
{
	this->_name = name;
	this->_type = type;
	std::cout << std::endl << "Zombie '" << name << "' was born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie '" << this->_name << "' was die" << std::endl << std::endl;
}

void			Zombie::setType(std::string type)
{
	this->_type = type;
}

void			Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string		Zombie::getType( void )
{
	return (this->_type);
}

std::string		Zombie::getName( void )
{
	return (this->_name);
}

void			Zombie::announce( void )
{
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}
