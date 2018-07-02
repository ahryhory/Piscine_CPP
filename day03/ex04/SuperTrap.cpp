/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 20:29:15 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/22 20:29:16 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name)
{
	_hitPoints = FragTrap::getHitPoints();
	_maxHitPoints = FragTrap::getMaxHitPoints();
	_energyPoints = NinjaTrap::getEnergyPoints();
	_maxEnergyPoints = NinjaTrap::getMaxEnergyPoints();
	_level = 1;
	_softAttackDamage = 5;
	_meleeAttackDamage = NinjaTrap::getMeleeAttackDamage();
	_sprintAttackDamage = 30;
	_rangedAttackDamage = FragTrap::getRangedAttackDamage();
	_nuclearAttackDamage = 65;
	_armorDamageReduction = FragTrap::getArmorDamageReduction();
	_name = name;
	std::cout << std::endl << "SuperTrap was born !" << std::endl;
}

SuperTrap::SuperTrap()
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
	std::cout << std::endl << "SuperTrap was born !" << std::endl;
}

SuperTrap::SuperTrap( SuperTrap const &src )
{
	*this = src;
}

SuperTrap::~SuperTrap()
{
	std::cout << std::endl << "SuperTrap was dead !" << std::endl;
}

SuperTrap	&SuperTrap::operator=( SuperTrap const &rhs)
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

void			SuperTrap::rangedAttack( std::string const & target )
{
	FragTrap::rangedAttack(target);
}

void			SuperTrap::meleeAttack( std::string const & target )
{
	NinjaTrap::meleeAttack(target);
}
