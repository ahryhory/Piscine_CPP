/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:43:43 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/22 13:43:44 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_softAttackDamage = 5;
	_meleeAttackDamage = 20;
	_sprintAttackDamage = 30;
	_rangedAttackDamage = 15;
	_nuclearAttackDamage = 65;
	_armorDamageReduction = 3;
	_name = name;
	std::cout << std::endl << "SC5G-TP was born !" << std::endl;
}

ScavTrap::ScavTrap()
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_softAttackDamage = 5;
	_meleeAttackDamage = 20;
	_sprintAttackDamage = 30;
	_rangedAttackDamage = 15;
	_nuclearAttackDamage = 65;
	_armorDamageReduction = 3;
	_name = "none";
	std::cout << std::endl << "SC5G-TP was born !" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &src )
{
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << std::endl << "SC5G-TP was dead !" << std::endl;
}

void		ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string		challenge[4] = {"Do something with ", "Do anything with ", "Do anything with ", "Do something with "};

	std::cout << std::endl << challenge[rand() % 4] << target << std::endl;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const &rhs)
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
