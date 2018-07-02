/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:00:15 by ahryhory          #+#    #+#             */
/*   Updated: 2018/06/21 19:00:16 by ahryhory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_level = 1;
	_softAttackDamage = 5;
	_meleeAttackDamage = 30;
	_sprintAttackDamage = 35;
	_rangedAttackDamage = 20;
	_nuclearAttackDamage = 65;
	_armorDamageReduction = 5;
	_name = name;
	std::cout << std::endl << "FR4G-TP was born !" << std::endl;
}

FragTrap::FragTrap()
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_level = 1;
	_softAttackDamage = 5;
	_meleeAttackDamage = 30;
	_sprintAttackDamage = 35;
	_rangedAttackDamage = 20;
	_nuclearAttackDamage = 65;
	_armorDamageReduction = 5;
	_name = "none";
	std::cout << std::endl << "FR4G-TP was born !" << std::endl;
}

FragTrap::FragTrap( FragTrap const &src )
{
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << std::endl << "FR4G-TP was dead !" << std::endl;
}

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	typedef void (FragTrap::*Attack)(std::string const & target);
	Attack	attack[5] = {&FragTrap::softAttack, &FragTrap::meleeAttack, &FragTrap::sprintAttack, &FragTrap::rangedAttack, &FragTrap::nuclearAttack};
	int		attackEnergy[5] = {1, 20, 25, 10, 90};
	int		randAttack;

	if (_energyPoints >= 25 && _hitPoints != 0)
	{
		std::cout << std::endl << "Random  attack ! ! !" << std::endl;
		randAttack = rand() % 5;
		_energyPoints += attackEnergy[randAttack];
		_energyPoints -= 25;
		(this->*(attack[randAttack]))(target);
		if (attackEnergy[randAttack] >= 25)
			std::cout << std::endl << "Good  random ) ! ! !" << std::endl;
		if (attackEnergy[randAttack] < 25)
			std::cout << std::endl << "Bad  random ( ! ! !" << std::endl;
	}
	else
	{
		if (_hitPoints == 0)
			std::cout << std::endl << "No hit points !" << std::endl;
		else
			std::cout << std::endl << "No energy points for random attack!" << std::endl;
	}
}

FragTrap	&FragTrap::operator=( FragTrap const &rhs)
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
