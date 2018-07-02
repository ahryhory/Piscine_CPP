/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:42:20 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/22 16:42:21 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

NinjaTrap::NinjaTrap(std::string name)
{
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_softAttackDamage = 5;
	_meleeAttackDamage = 60;
	_sprintAttackDamage = 35;
	_rangedAttackDamage = 5;
	_nuclearAttackDamage = 65;
	_armorDamageReduction = 0;
	_name = name;
	std::cout << std::endl << "Ninja was born !" << std::endl;
}

NinjaTrap::NinjaTrap()
{
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_softAttackDamage = 5;
	_meleeAttackDamage = 60;
	_sprintAttackDamage = 35;
	_rangedAttackDamage = 5;
	_nuclearAttackDamage = 65;
	_armorDamageReduction = 0;
	_name = "none";
	std::cout << std::endl << "Ninja was born !" << std::endl;
}

NinjaTrap::NinjaTrap( NinjaTrap const &src )
{
	*this = src;
}

void		NinjaTrap::ninjaShoebox( NinjaTrap & src )
{
	std::cout << std::endl << "Ninja & Ninja !" << std::endl;
	std::cout << std::endl << _name << " & " << src.getName() << " !" << std::endl;
}

void		NinjaTrap::ninjaShoebox( FragTrap & src )
{
	std::cout << std::endl << "FragTrap & Ninja !" << std::endl;
	std::cout << std::endl << _name << " & " << src.getName() << " !" << std::endl;
}

void		NinjaTrap::ninjaShoebox( ScavTrap & src )
{
	std::cout << std::endl << "ScavTrap & Ninja !" << std::endl;
	std::cout << std::endl << _name << " & " << src.getName() << " !" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << std::endl << "Ninja was dead !" << std::endl;
}

NinjaTrap	&NinjaTrap::operator=( NinjaTrap const &rhs)
{
	if (this != &rhs)
	{
		_hitPoints = rhs._hitPoints;
		_maxHitPoints = rhs._maxHitPoints;
		_energyPoints = rhs._energyPoints;
		_maxEnergyPoints = rhs._maxEnergyPoints;
		_level = rhs._level;
		_softAttackDamage = rhs._softAttackDamage;
		_sprintAttackDamage = rhs._sprintAttackDamage;
		_nuclearAttackDamage = rhs._nuclearAttackDamage;
		_meleeAttackDamage = rhs._meleeAttackDamage;
		_rangedAttackDamage = rhs._rangedAttackDamage;
		_armorDamageReduction = rhs._armorDamageReduction;
		_name = rhs._name;
	}
	return *this;
}
